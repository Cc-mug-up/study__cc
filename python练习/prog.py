# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn.datasets import make_blobs
import matplotlib.patches as mpatches
import tkinter as tk
from tkinter import ttk, messagebox
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure
import warnings
warnings.filterwarnings('ignore')

class ClusteringApp:
    def __init__(self, root):
        self.root = root
        self.root.title("聚类算法对比演示程序")
        self.root.geometry("1400x900")
        
        # 初始化参数
        self.init_parameters()
        
        # 创建GUI
        self.create_widgets()
        
        # 首次生成图片
        self.generate_plot()
    
    def init_parameters(self):
        """初始化所有可调参数"""
        # 左图参数
        self.left_params = {
            'n_samples': tk.IntVar(value=120),  # 元素数量
            'center_x': tk.DoubleVar(value=2.0),  # 聚集点X坐标绝对值
            'center_y': tk.DoubleVar(value=2.0),  # 聚集点Y坐标绝对值
            'std': tk.DoubleVar(value=0.5),  # 标准差
            'marker_size': tk.IntVar(value=22),  # 点的大小
            'inner_radius': tk.DoubleVar(value=1.6),  # 内圈半径
            'outer_radius': tk.DoubleVar(value=2.8),  # 外圈半径
            'xlim': tk.DoubleVar(value=5.0),  # X轴范围
            'ylim': tk.DoubleVar(value=5.0),  # Y轴范围
        }
        
        # 右图参数
        self.right_params = {
            'n_samples': tk.IntVar(value=80),  # 元素数量
            'center_x': tk.DoubleVar(value=1.5),  # 聚集点X坐标绝对值
            'center_y': tk.DoubleVar(value=1.5),  # 聚集点Y坐标绝对值
            'std': tk.DoubleVar(value=0.6),  # 标准差
            'marker_size': tk.IntVar(value=25),  # 点的大小
            'xlim': tk.DoubleVar(value=4.0),  # X轴范围
            'ylim': tk.DoubleVar(value=4.0),  # Y轴范围
        }
        
        # 通用参数
        self.common_params = {
            'title_font': tk.IntVar(value=14),
            'label_font': tk.IntVar(value=12),
            'tick_font': tk.IntVar(value=11),
            'legend_font': tk.IntVar(value=10),
            'grid_alpha': tk.DoubleVar(value=0.3),
        }
    
    def create_widgets(self):
        """创建GUI界面"""
        # 创建主框架
        main_frame = ttk.Frame(self.root, padding="10")
        main_frame.grid(row=0, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))
        
        # 左侧控制面板
        control_frame = ttk.LabelFrame(main_frame, text="控制面板", padding="10")
        control_frame.grid(row=0, column=0, sticky=(tk.N, tk.W, tk.E), padx=(0, 10))
        
        # 右图画布区域
        canvas_frame = ttk.Frame(main_frame)
        canvas_frame.grid(row=0, column=1, sticky=(tk.N, tk.W, tk.E, tk.S))
        
        # 创建控制面板内容
        self.create_control_panel(control_frame)
        
        # 创建画布
        self.create_canvas(canvas_frame)
        
        # 配置网格权重
        self.root.columnconfigure(0, weight=1)
        self.root.rowconfigure(0, weight=1)
        main_frame.columnconfigure(1, weight=1)
        main_frame.rowconfigure(0, weight=1)
    
    def create_control_panel(self, parent):
        """创建控制面板"""
        # 左图参数
        left_frame = ttk.LabelFrame(parent, text="左图参数 (Canopy聚类)", padding="10")
        left_frame.pack(fill=tk.X, pady=(0, 10))
        
        self.create_parameter_controls(left_frame, "左图", self.left_params, [
            ("元素数量:", "n_samples", 50, 300, 10),
            ("X坐标绝对值:", "center_x", 0.5, 5.0, 0.1),
            ("Y坐标绝对值:", "center_y", 0.5, 5.0, 0.1),
            ("标准差:", "std", 0.1, 2.0, 0.1),
            ("点的大小:", "marker_size", 5, 50, 1),
            ("内圈半径:", "inner_radius", 0.5, 4.0, 0.1),
            ("外圈半径:", "outer_radius", 1.0, 6.0, 0.1),
            ("X轴范围:", "xlim", 2.0, 10.0, 0.5),
            ("Y轴范围:", "ylim", 2.0, 10.0, 0.5),
        ])
        
        # 右图参数
        right_frame = ttk.LabelFrame(parent, text="右图参数 (K-means聚类)", padding="10")
        right_frame.pack(fill=tk.X, pady=(0, 10))
        
        self.create_parameter_controls(right_frame, "右图", self.right_params, [
            ("元素数量:", "n_samples", 20, 200, 5),
            ("X坐标绝对值:", "center_x", 0.5, 4.0, 0.1),
            ("Y坐标绝对值:", "center_y", 0.5, 4.0, 0.1),
            ("标准差:", "std", 0.1, 2.0, 0.1),
            ("点的大小:", "marker_size", 5, 50, 1),
            ("X轴范围:", "xlim", 2.0, 8.0, 0.5),
            ("Y轴范围:", "ylim", 2.0, 8.0, 0.5),
        ])
        
        # 通用参数
        common_frame = ttk.LabelFrame(parent, text="通用参数", padding="10")
        common_frame.pack(fill=tk.X, pady=(0, 10))
        
        self.create_parameter_controls(common_frame, "通用", self.common_params, [
            ("标题字体:", "title_font", 8, 20, 1),
            ("标签字体:", "label_font", 8, 18, 1),
            ("刻度字体:", "tick_font", 8, 16, 1),
            ("图例字体:", "legend_font", 8, 16, 1),
            ("网格透明度:", "grid_alpha", 0.0, 1.0, 0.05),
        ])
        
        # 按钮区域
        button_frame = ttk.Frame(parent)
        button_frame.pack(fill=tk.X, pady=(10, 0))
        
        ttk.Button(button_frame, text="生成图片", command=self.generate_plot).pack(side=tk.LEFT, padx=(0, 10))
        ttk.Button(button_frame, text="保存图片", command=self.save_plot).pack(side=tk.LEFT, padx=(0, 10))
        ttk.Button(button_frame, text="重置参数", command=self.reset_parameters).pack(side=tk.LEFT, padx=(0, 10))
        ttk.Button(button_frame, text="退出程序", command=self.root.quit).pack(side=tk.LEFT)
        
        # 状态栏
        self.status_var = tk.StringVar(value="就绪")
        ttk.Label(parent, textvariable=self.status_var, relief=tk.SUNKEN).pack(fill=tk.X, pady=(10, 0))
    
    def create_parameter_controls(self, parent, prefix, params, controls):
        """为给定的参数创建控制控件"""
        for i, (label, key, min_val, max_val, step) in enumerate(controls):
            frame = ttk.Frame(parent)
            frame.pack(fill=tk.X, pady=2)
            
            ttk.Label(frame, text=label, width=12).pack(side=tk.LEFT)
            
            var = params[key]
            scale = ttk.Scale(frame, from_=min_val, to=max_val, variable=var, 
                             orient=tk.HORIZONTAL, length=150)
            scale.pack(side=tk.LEFT, padx=(5, 5))
            
            # 显示当前值
            value_label = ttk.Label(frame, textvariable=var, width=6)
            value_label.pack(side=tk.LEFT)
            
            # 绑定滑块变化事件
            scale.bind('<B1-Motion>', lambda e, p=prefix, k=key: self.on_parameter_change(p, k))
            scale.bind('<ButtonRelease-1>', lambda e, p=prefix, k=key: self.on_parameter_change(p, k))
    
    def create_canvas(self, parent):
        """创建Matplotlib画布"""
        # 创建图形
        self.fig = Figure(figsize=(12, 6), dpi=100)
        
        # 创建子图
        self.ax1 = self.fig.add_subplot(121)  # 左图
        self.ax2 = self.fig.add_subplot(122)  # 右图
        
        # 设置中文字体
        plt.rcParams['font.sans-serif'] = ['SimHei', 'Microsoft YaHei', 'DejaVu Sans']
        plt.rcParams['axes.unicode_minus'] = False
        
        # 创建画布
        self.canvas = FigureCanvasTkAgg(self.fig, master=parent)
        self.canvas.draw()
        self.canvas.get_tk_widget().pack(fill=tk.BOTH, expand=True)
    
    def on_parameter_change(self, prefix, key):
        """参数变化时的回调函数"""
        self.status_var.set(f"调整{prefix}的{key}...")
        self.generate_plot()
    
    def generate_plot(self):
        """生成聚类对比图"""
        try:
            # 清除之前的图形
            self.ax1.clear()
            self.ax2.clear()
            
            # 获取当前参数值
            left_samples = self.left_params['n_samples'].get()
            left_center_x = self.left_params['center_x'].get()
            left_center_y = self.left_params['center_y'].get()
            left_std = self.left_params['std'].get()
            left_marker_size = self.left_params['marker_size'].get()
            left_T2 = self.left_params['inner_radius'].get()
            left_T1 = self.left_params['outer_radius'].get()
            left_xlim = self.left_params['xlim'].get()
            left_ylim = self.left_params['ylim'].get()
            
            right_samples = self.right_params['n_samples'].get()
            right_center_x = self.right_params['center_x'].get()
            right_center_y = self.right_params['center_y'].get()
            right_std = self.right_params['std'].get()
            right_marker_size = self.right_params['marker_size'].get()
            right_xlim = self.right_params['xlim'].get()
            right_ylim = self.right_params['ylim'].get()
            
            title_font = self.common_params['title_font'].get()
            label_font = self.common_params['label_font'].get()
            tick_font = self.common_params['tick_font'].get()
            legend_font = self.common_params['legend_font'].get()
            grid_alpha = self.common_params['grid_alpha'].get()
            
            # 设置随机种子
            np.random.seed(42)
            
            # 颜色和标记设置
            colors = ['cyan', 'gold', 'red', 'green']
            markers = ['^', '*', 'd', 'v']
            
            # 1. 左图: Canopy聚类
            centers_left = np.array([
                [left_center_x, left_center_y],
                [left_center_x, -left_center_y],
                [-left_center_x, left_center_y],
                [-left_center_x, -left_center_y]
            ])
            
            X_left, y_left = make_blobs(
                n_samples=left_samples,
                centers=centers_left,
                cluster_std=[left_std] * 4,
                random_state=42
            )
            
            # 绘制左图
            for i, center in enumerate(centers_left):
                cluster_points = X_left[y_left == i]
                self.ax1.scatter(
                    cluster_points[:, 0], cluster_points[:, 1],
                    c=colors[i], marker=markers[i], s=left_marker_size,
                    edgecolors='none', alpha=0.85, zorder=5
                )
                
                # 绘制内圈（红色实线）
                circle_t2 = mpatches.Circle(
                    center, left_T2,
                    fill=False,
                    edgecolor='red',
                    linewidth=1.8,
                    linestyle='-',
                    alpha=0.9
                )
                self.ax1.add_patch(circle_t2)
                
                # 绘制外圈（蓝色虚线）
                circle_t1 = mpatches.Circle(
                    center, left_T1,
                    fill=False,
                    edgecolor='blue',
                    linewidth=1.4,
                    linestyle='--',
                    alpha=0.8
                )
                self.ax1.add_patch(circle_t1)
                
                # 绘制内聚点
                self.ax1.scatter(
                    center[0], center[1],
                    c='black', marker='+', s=180, linewidth=2.2,
                    zorder=6
                )
            
            # 设置左图样式
            self.ax1.set_xlabel('X', fontsize=label_font)
            self.ax1.set_ylabel('Y', fontsize=label_font)
            self.ax1.set_title('图8 canopy 聚类效果图', fontsize=title_font, fontweight='bold')
            self.ax1.grid(True, alpha=grid_alpha, linewidth=0.6)
            self.ax1.set_xlim(-left_xlim, left_xlim)
            self.ax1.set_ylim(-left_ylim, left_ylim)
            self.ax1.set_aspect('equal', 'box')
            self.ax1.tick_params(axis='both', which='major', labelsize=tick_font)
            
            # 2. 右图: K-means聚类
            centers_right = np.array([
                [right_center_x, right_center_y],
                [right_center_x, -right_center_y],
                [-right_center_x, right_center_y],
                [-right_center_x, -right_center_y]
            ])
            
            X_right, y_right = make_blobs(
                n_samples=right_samples,
                centers=centers_right,
                cluster_std=[right_std] * 4,
                random_state=42
            )
            
            # 应用K-means聚类
            kmeans = KMeans(n_clusters=4, init=centers_right, n_init=1, random_state=42)
            kmeans_labels = kmeans.fit_predict(X_right)
            kmeans_centers = kmeans.cluster_centers_
            
            # 绘制右图
            for i in range(4):
                cluster_points = X_right[kmeans_labels == i]
                self.ax2.scatter(
                    cluster_points[:, 0], cluster_points[:, 1],
                    c=colors[i], marker=markers[i], s=right_marker_size,
                    edgecolors='none', alpha=0.85, zorder=2
                )
            
            # 绘制K-means中心点
            self.ax2.scatter(
                kmeans_centers[:, 0], kmeans_centers[:, 1],
                c='black', marker='+', s=180, linewidth=2.2,
                zorder=5
            )
            
            # 设置右图样式
            self.ax2.set_xlabel('X', fontsize=label_font)
            self.ax2.set_ylabel('Y', fontsize=label_font)
            self.ax2.set_title('图8 k-means 聚类效果图', fontsize=title_font, fontweight='bold')
            self.ax2.grid(True, alpha=grid_alpha, linewidth=0.6)
            self.ax2.set_xlim(-right_xlim, right_xlim)
            self.ax2.set_ylim(-right_ylim, right_ylim)
            self.ax2.set_aspect('equal', 'box')
            self.ax2.tick_params(axis='both', which='major', labelsize=tick_font)
            
            # 添加图例
            from matplotlib.lines import Line2D
            legend_elements = [
                Line2D([0], [0], marker='^', color='w', markerfacecolor='cyan',
                       markersize=12, label='Cluster 1 (青色三角形)', markeredgecolor='none'),
                Line2D([0], [0], marker='*', color='w', markerfacecolor='gold',
                       markersize=12, label='Cluster 2 (金色星号)', markeredgecolor='none'),
                Line2D([0], [0], marker='d', color='w', markerfacecolor='red',
                       markersize=12, label='Cluster 3 (红色菱形)', markeredgecolor='none'),
                Line2D([0], [0], marker='v', color='w', markerfacecolor='green',
                       markersize=12, label='Cluster 4 (绿色倒三角形)', markeredgecolor='none'),
                Line2D([0], [0], marker='+', color='black', lw=2.2, markersize=12,
                       label='聚类中心', markeredgewidth=2.2)
            ]
            
            legend_elements_left = legend_elements + [
                Line2D([0], [0], color='red', lw=1.8, label='内阈半径 (红色实线)'),
                Line2D([0], [0], color='blue', lw=1.4, linestyle='--', label='外阈半径 (蓝色虚线)')
            ]
            
            self.ax1.legend(handles=legend_elements_left, loc='upper right', fontsize=legend_font, framealpha=0.9)
            self.ax2.legend(handles=legend_elements, loc='upper right', fontsize=legend_font, framealpha=0.9)
            
            # 调整布局
            self.fig.tight_layout()
            
            # 更新画布
            self.canvas.draw()
            
            self.status_var.set("图片生成成功！")
            
        except Exception as e:
            messagebox.showerror("错误", f"生成图片时出错:\n{str(e)}")
            self.status_var.set("错误：" + str(e))
    
    def save_plot(self):
        """保存当前图片到文件"""
        try:
            from tkinter import filedialog
            import datetime
            
            # 生成默认文件名
            default_name = f"聚类算法对比_{datetime.datetime.now().strftime('%Y%m%d_%H%M%S')}.png"
            
            # 打开文件对话框
            filename = filedialog.asksaveasfilename(
                defaultextension=".png",
                filetypes=[("PNG图片", "*.png"), ("所有文件", "*.*")],
                initialfile=default_name
            )
            
            if filename:
                self.fig.savefig(filename, dpi=300, bbox_inches='tight', facecolor='white', edgecolor='none')
                self.status_var.set(f"图片已保存到: {filename}")
                messagebox.showinfo("成功", f"图片已保存到:\n{filename}")
                
        except Exception as e:
            messagebox.showerror("错误", f"保存图片时出错:\n{str(e)}")
            self.status_var.set("错误：" + str(e))
    
    def reset_parameters(self):
        """重置所有参数为默认值"""
        # 左图默认值
        self.left_params['n_samples'].set(120)
        self.left_params['center_x'].set(2.0)
        self.left_params['center_y'].set(2.0)
        self.left_params['std'].set(0.5)
        self.left_params['marker_size'].set(22)
        self.left_params['inner_radius'].set(1.6)
        self.left_params['outer_radius'].set(2.8)
        self.left_params['xlim'].set(5.0)
        self.left_params['ylim'].set(5.0)
        
        # 右图默认值
        self.right_params['n_samples'].set(80)
        self.right_params['center_x'].set(1.5)
        self.right_params['center_y'].set(1.5)
        self.right_params['std'].set(0.6)
        self.right_params['marker_size'].set(25)
        self.right_params['xlim'].set(4.0)
        self.right_params['ylim'].set(4.0)
        
        # 通用参数默认值
        self.common_params['title_font'].set(14)
        self.common_params['label_font'].set(12)
        self.common_params['tick_font'].set(11)
        self.common_params['legend_font'].set(10)
        self.common_params['grid_alpha'].set(0.3)
        
        # 重新生成图片
        self.generate_plot()
        self.status_var.set("参数已重置为默认值")

def main():
    """主函数"""
    root = tk.Tk()
    app = ClusteringApp(root)
    root.mainloop()

if __name__ == "__main__":
    main()