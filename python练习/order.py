# -*- coding: utf-8 -*-
import tkinter as tk
from tkinter import ttk, messagebox, scrolledtext
import json
import os
from datetime import datetime

class RestaurantOrderSystem:
    def __init__(self):
        self.window = tk.Tk()
        self.window.title("马年吉祥餐厅点餐系统")
        self.window.geometry("1100x700")
        self.window.configure(bg="#f0f0f0")
        
        # 餐厅信息
        self.restaurant_name = "马年吉祥餐厅"
        self.current_year = "丙午马年"
        
        # 初始化数据
        self.current_order = {}
        self.order_history = []
        self.menu_items = self.load_menu()
        self.current_table = 1
        self.order_number = 1
        
        # 加载历史订单
        self.load_order_history()
        
        # 创建GUI
        self.create_widgets()
        
        # 设置窗口关闭事件
        self.window.protocol("WM_DELETE_WINDOW", self.on_closing)
        
    def load_menu(self):
        """加载菜单数据"""
        menu = {
            "凉菜": [
                {"id": "C01", "name": "凉拌黄瓜", "price": 12, "description": "清爽开胃，夏日必备"},
                {"id": "C02", "name": "夫妻肺片", "price": 28, "description": "麻辣鲜香，经典川味"},
                {"id": "C03", "name": "老醋蛰头", "price": 32, "description": "酸甜爽口，开胃佳品"},
                {"id": "C04", "name": "口水鸡", "price": 35, "description": "麻辣鲜香，肉质鲜嫩"},
            ],
            "热菜": [
                {"id": "H01", "name": "宫保鸡丁", "price": 38, "description": "经典川菜，甜辣适口"},
                {"id": "H02", "name": "红烧肉", "price": 58, "description": "肥而不腻，入口即化"},
                {"id": "H03", "name": "清蒸鲈鱼", "price": 68, "description": "鱼肉鲜嫩，原汁原味"},
                {"id": "H04", "name": "鱼香肉丝", "price": 36, "description": "鱼香味浓，下饭神器"},
                {"id": "H05", "name": "麻婆豆腐", "price": 28, "description": "麻辣鲜香，豆腐嫩滑"},
                {"id": "H06", "name": "水煮肉片", "price": 48, "description": "麻辣过瘾，肉片滑嫩"},
            ],
            "主食": [
                {"id": "S01", "name": "扬州炒饭", "price": 25, "description": "粒粒分明，香气扑鼻"},
                {"id": "S02", "name": "牛肉拉面", "price": 22, "description": "面条劲道，汤头鲜美"},
                {"id": "S03", "name": "饺子(12个)", "price": 28, "description": "手工制作，馅料丰富"},
                {"id": "S04", "name": "葱油饼", "price": 15, "description": "外酥里嫩，葱香四溢"},
            ],
            "汤类": [
                {"id": "T01", "name": "酸辣汤", "price": 18, "description": "酸辣开胃，暖心暖胃"},
                {"id": "T02", "name": "西湖牛肉羹", "price": 28, "description": "牛肉鲜嫩，汤味醇厚"},
                {"id": "T03", "name": "紫菜蛋花汤", "price": 15, "description": "清淡爽口，家常味道"},
            ],
            "饮料": [
                {"id": "D01", "name": "可乐", "price": 5, "description": "经典碳酸饮料"},
                {"id": "D02", "name": "雪碧", "price": 5, "description": "清爽柠檬味"},
                {"id": "D03", "name": "橙汁", "price": 8, "description": "100%鲜榨橙汁"},
                {"id": "D04", "name": "啤酒", "price": 10, "description": "冰镇啤酒，夏日必备"},
                {"id": "D05", "name": "酸梅汤", "price": 12, "description": "传统饮品，消暑解渴"},
            ],
            "甜点": [
                {"id": "DSS01", "name": "芒果布丁", "price": 18, "description": "口感细腻，芒果味浓"},
                {"id": "DSS02", "name": "芝麻汤圆", "price": 15, "description": "香甜软糯，传统甜点"},
                {"id": "DSS03", "name": "水果拼盘", "price": 25, "description": "时令水果，新鲜美味"},
            ]
        }
        return menu
    
    def load_order_history(self):
        """加载历史订单数据"""
        try:
            if os.path.exists("order_history.json"):
                with open("order_history.json", "r", encoding="utf-8") as f:
                    self.order_history = json.load(f)
        except:
            self.order_history = []
    
    def save_order_history(self):
        """保存订单历史"""
        try:
            with open("order_history.json", "w", encoding="utf-8") as f:
                json.dump(self.order_history, f, ensure_ascii=False, indent=2)
        except:
            pass
    
    def create_widgets(self):
        """创建GUI界面"""
        # 标题栏
        title_frame = tk.Frame(self.window, bg="#d32f2f", height=80)
        title_frame.pack(fill=tk.X)
        title_frame.pack_propagate(False)
        
        title_label = tk.Label(title_frame, text=self.restaurant_name, 
                               font=("微软雅黑", 24, "bold"), 
                               fg="white", bg="#d32f2f")
        title_label.pack(pady=10)
        
        subtitle_label = tk.Label(title_frame, text=f"{self.current_year} 新年快乐 • 扫码点餐", 
                                 font=("微软雅黑", 12), 
                                 fg="#ffcc00", bg="#d32f2f")
        subtitle_label.pack()
        
        # 主内容区域
        main_frame = tk.Frame(self.window, bg="#f0f0f0")
        main_frame.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)
        
        # 创建左右分割的框架
        paned_window = tk.PanedWindow(main_frame, orient=tk.HORIZONTAL, sashwidth=5, sashrelief=tk.RAISED)
        paned_window.pack(fill=tk.BOTH, expand=True)
        
        # 左侧菜单区域
        left_frame = tk.Frame(paned_window, bg="#ffffff", bd=2, relief=tk.RIDGE)
        
        # 右侧订单区域
        right_frame = tk.Frame(paned_window, bg="#ffffff", bd=2, relief=tk.RIDGE)
        
        # 添加到PaneWindow
        paned_window.add(left_frame, width=700)  # 左侧宽度
        paned_window.add(right_frame, width=350)  # 右侧宽度
        
        # 创建左侧菜单
        self.create_menu_section(left_frame)
        
        # 创建右侧订单
        self.create_order_section(right_frame)
        
    def create_menu_section(self, parent):
        """创建菜单显示区域"""
        # 菜单类别标签
        categories_frame = tk.Frame(parent, bg="#ffffff")
        categories_frame.pack(fill=tk.X, padx=10, pady=10)
        
        categories = list(self.menu_items.keys())
        self.category_buttons = {}
        
        for i, category in enumerate(categories):
            btn = tk.Button(categories_frame, text=category, 
                           font=("微软雅黑", 11),
                           bg="#f5f5f5", fg="#333333",
                           relief=tk.RAISED,
                           command=lambda c=category: self.show_category_items(c))
            btn.pack(side=tk.LEFT, padx=5, pady=5)
            self.category_buttons[category] = btn
        
        # 默认选中第一个类别
        self.show_category_items(categories[0])
        
        # 菜单项目显示区域
        self.menu_canvas = tk.Canvas(parent, bg="#ffffff", highlightthickness=0)
        scrollbar = ttk.Scrollbar(parent, orient="vertical", command=self.menu_canvas.yview)
        
        self.menu_items_frame = tk.Frame(self.menu_canvas, bg="#ffffff")
        
        self.menu_canvas.create_window((0, 0), window=self.menu_items_frame, anchor="nw")
        self.menu_canvas.configure(yscrollcommand=scrollbar.set)
        
        self.menu_canvas.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=(10, 0), pady=(0, 10))
        scrollbar.pack(side=tk.RIGHT, fill=tk.Y, pady=(0, 10))
        
        # 绑定滚动事件
        self.menu_items_frame.bind("<Configure>", 
                                  lambda e: self.menu_canvas.configure(scrollregion=self.menu_canvas.bbox("all")))
        
    def show_category_items(self, category):
        """显示指定类别的菜单项目"""
        # 重置按钮颜色
        for cat, btn in self.category_buttons.items():
            btn.configure(bg="#f5f5f5" if cat != category else "#d32f2f", 
                         fg="#333333" if cat != category else "white")
        
        # 清除当前显示
        for widget in self.menu_items_frame.winfo_children():
            widget.destroy()
        
        # 显示新类别的项目
        items = self.menu_items.get(category, [])
        
        for i, item in enumerate(items):
            # 创建菜品项框架
            item_frame = tk.Frame(self.menu_items_frame, bg="#ffffff", bd=1, relief=tk.RIDGE)
            item_frame.pack(fill=tk.X, padx=5, pady=5, ipady=5)
            
            # 菜品信息
            info_frame = tk.Frame(item_frame, bg="#ffffff")
            info_frame.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=10, pady=5)
            
            name_label = tk.Label(info_frame, text=f"{item['name']}", 
                                 font=("微软雅黑", 12, "bold"), 
                                 bg="#ffffff", fg="#333333", anchor="w")
            name_label.pack(anchor="w")
            
            desc_label = tk.Label(info_frame, text=item['description'], 
                                 font=("微软雅黑", 9), 
                                 bg="#ffffff", fg="#666666", anchor="w")
            desc_label.pack(anchor="w", pady=(2, 0))
            
            price_label = tk.Label(info_frame, text=f"¥{item['price']:.2f}", 
                                  font=("微软雅黑", 11, "bold"), 
                                  bg="#ffffff", fg="#d32f2f", anchor="w")
            price_label.pack(anchor="w", pady=(2, 0))
            
            # 数量选择和添加按钮
            control_frame = tk.Frame(item_frame, bg="#ffffff")
            control_frame.pack(side=tk.RIGHT, padx=10, pady=5)
            
            # 减少数量按钮
            minus_btn = tk.Button(control_frame, text="-", 
                                 font=("微软雅黑", 10, "bold"),
                                 width=2, height=1,
                                 bg="#e0e0e0", fg="#333333",
                                 command=lambda id=item['id'], name=item['name']: self.decrease_quantity(id, name))
            minus_btn.pack(side=tk.LEFT, padx=(0, 2))
            
            # 数量显示
            quantity = self.current_order.get(item['id'], {}).get('quantity', 0)
            qty_label = tk.Label(control_frame, text=str(quantity), 
                                font=("微软雅黑", 11), 
                                width=3, bg="#ffffff", relief=tk.SUNKEN)
            qty_label.pack(side=tk.LEFT)
            
            # 增加数量按钮
            plus_btn = tk.Button(control_frame, text="+", 
                                font=("微软雅黑", 10, "bold"),
                                width=2, height=1,
                                bg="#e0e0e0", fg="#333333",
                                command=lambda id=item['id'], name=item['name'], 
                                               price=item['price'], desc=item['description']: 
                                self.increase_quantity(id, name, price, desc))
            plus_btn.pack(side=tk.LEFT, padx=(2, 10))
            
            # 保存数量标签的引用以便更新
            self.current_order[item['id']] = {
                'quantity': quantity,
                'name': item['name'],
                'price': item['price'],
                'label': qty_label
            }
        
    def increase_quantity(self, item_id, name, price, description):
        """增加菜品数量"""
        if item_id not in self.current_order:
            self.current_order[item_id] = {
                'quantity': 0,
                'name': name,
                'price': price,
                'description': description
            }
        
        self.current_order[item_id]['quantity'] += 1
        
        # 更新显示的数量
        if 'label' in self.current_order[item_id]:
            self.current_order[item_id]['label'].config(
                text=str(self.current_order[item_id]['quantity'])
            )
        
        # 更新订单显示
        self.update_order_display()
        
    def decrease_quantity(self, item_id, name):
        """减少菜品数量"""
        if item_id in self.current_order:
            if self.current_order[item_id]['quantity'] > 0:
                self.current_order[item_id]['quantity'] -= 1
                
                # 更新显示的数量
                if 'label' in self.current_order[item_id]:
                    self.current_order[item_id]['label'].config(
                        text=str(self.current_order[item_id]['quantity'])
                    )
                
                # 如果数量为0，从当前订单移除
                if self.current_order[item_id]['quantity'] == 0:
                    # 不从字典移除，但更新显示
                    pass
                
                # 更新订单显示
                self.update_order_display()
    
    def create_order_section(self, parent):
        """创建订单显示区域"""
        # 订单标题
        order_title_frame = tk.Frame(parent, bg="#ffffff")
        order_title_frame.pack(fill=tk.X, padx=10, pady=10)
        
        order_title = tk.Label(order_title_frame, text="当前订单", 
                              font=("微软雅黑", 16, "bold"), 
                              bg="#ffffff", fg="#333333")
        order_title.pack(side=tk.LEFT)
        
        # 桌号选择
        table_frame = tk.Frame(order_title_frame, bg="#ffffff")
        table_frame.pack(side=tk.RIGHT)
        
        tk.Label(table_frame, text="桌号:", 
                font=("微软雅黑", 10), 
                bg="#ffffff", fg="#666666").pack(side=tk.LEFT)
        
        self.table_var = tk.StringVar(value=str(self.current_table))
        table_spinbox = ttk.Spinbox(table_frame, from_=1, to=50, 
                                    textvariable=self.table_var,
                                    width=5, font=("微软雅黑", 10))
        table_spinbox.pack(side=tk.LEFT, padx=(5, 0))
        
        # 订单号显示
        order_num_frame = tk.Frame(parent, bg="#ffffff")
        order_num_frame.pack(fill=tk.X, padx=10, pady=(0, 10))
        
        self.order_num_label = tk.Label(order_num_frame, 
                                       text=f"订单号: #{self.order_number:04d}", 
                                       font=("微软雅黑", 11), 
                                       bg="#ffffff", fg="#d32f2f")
        self.order_num_label.pack(anchor="w")
        
        # 订单项目显示区域
        order_items_frame = tk.Frame(parent, bg="#f9f9f9", bd=1, relief=tk.SUNKEN)
        order_items_frame.pack(fill=tk.BOTH, expand=True, padx=10, pady=(0, 10))
        
        # 创建Canvas和Scrollbar用于订单项目
        self.order_canvas = tk.Canvas(order_items_frame, bg="#f9f9f9", highlightthickness=0)
        scrollbar = ttk.Scrollbar(order_items_frame, orient="vertical", command=self.order_canvas.yview)
        
        self.order_items_frame = tk.Frame(self.order_canvas, bg="#f9f9f9")
        
        self.order_canvas.create_window((0, 0), window=self.order_items_frame, anchor="nw")
        self.order_canvas.configure(yscrollcommand=scrollbar.set)
        
        self.order_canvas.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
        
        # 绑定滚动事件
        self.order_items_frame.bind("<Configure>", 
                                   lambda e: self.order_canvas.configure(scrollregion=self.order_canvas.bbox("all")))
        
        # 订单汇总
        summary_frame = tk.Frame(parent, bg="#ffffff", bd=1, relief=tk.RIDGE)
        summary_frame.pack(fill=tk.X, padx=10, pady=(0, 10))
        
        # 小计
        self.subtotal_label = tk.Label(summary_frame, text="小计: ¥0.00", 
                                      font=("微软雅黑", 11), 
                                      bg="#ffffff", fg="#333333")
        self.subtotal_label.pack(anchor="w", padx=10, pady=(10, 2))
        
        # 服务费 (10%)
        self.service_label = tk.Label(summary_frame, text="服务费(10%): ¥0.00", 
                                     font=("微软雅黑", 11), 
                                     bg="#ffffff", fg="#666666")
        self.service_label.pack(anchor="w", padx=10, pady=2)
        
        # 总计
        self.total_label = tk.Label(summary_frame, text="总计: ¥0.00", 
                                   font=("微软雅黑", 14, "bold"), 
                                   bg="#ffffff", fg="#d32f2f")
        self.total_label.pack(anchor="w", padx=10, pady=(2, 10))
        
        # 按钮区域
        button_frame = tk.Frame(parent, bg="#ffffff")
        button_frame.pack(fill=tk.X, padx=10, pady=(0, 10))
        
        # 提交订单按钮
        submit_btn = tk.Button(button_frame, text="提交订单", 
                              font=("微软雅黑", 12, "bold"),
                              bg="#4CAF50", fg="white",
                              padx=20, pady=10,
                              command=self.submit_order)
        submit_btn.pack(side=tk.LEFT, fill=tk.X, expand=True, padx=(0, 5))
        
        # 清除订单按钮
        clear_btn = tk.Button(button_frame, text="清除订单", 
                             font=("微软雅黑", 12),
                             bg="#f44336", fg="white",
                             padx=20, pady=10,
                             command=self.clear_order)
        clear_btn.pack(side=tk.LEFT, fill=tk.X, expand=True, padx=(5, 0))
        
        # 查看历史订单按钮
        history_btn = tk.Button(parent, text="查看历史订单", 
                               font=("微软雅黑", 11),
                               bg="#2196F3", fg="white",
                               padx=10, pady=8,
                               command=self.show_order_history)
        history_btn.pack(fill=tk.X, padx=10, pady=(0, 10))
    
    def update_order_display(self):
        """更新订单显示"""
        # 清除当前显示
        for widget in self.order_items_frame.winfo_children():
            widget.destroy()
        
        # 计算总计
        subtotal = 0
        
        # 显示每个订单项目
        for item_id, item_info in self.current_order.items():
            quantity = item_info.get('quantity', 0)
            
            if quantity > 0:
                name = item_info.get('name', '未知菜品')
                price = item_info.get('price', 0)
                description = item_info.get('description', '')
                
                item_total = quantity * price
                subtotal += item_total
                
                # 创建订单项框架
                order_item_frame = tk.Frame(self.order_items_frame, bg="#ffffff", bd=1, relief=tk.RIDGE)
                order_item_frame.pack(fill=tk.X, padx=5, pady=2, ipady=5)
                
                # 菜品信息
                info_frame = tk.Frame(order_item_frame, bg="#ffffff")
                info_frame.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=5)
                
                name_qty_label = tk.Label(info_frame, text=f"{name} × {quantity}", 
                                         font=("微软雅黑", 11), 
                                         bg="#ffffff", fg="#333333", anchor="w")
                name_qty_label.pack(anchor="w")
                
                # 价格
                price_label = tk.Label(info_frame, text=f"¥{item_total:.2f}", 
                                      font=("微软雅黑", 10), 
                                      bg="#ffffff", fg="#d32f2f", anchor="w")
                price_label.pack(anchor="w", pady=(2, 0))
                
                # 删除按钮
                delete_btn = tk.Button(order_item_frame, text="×", 
                                      font=("微软雅黑", 12, "bold"),
                                      width=2, height=1,
                                      bg="#ff5252", fg="white",
                                      command=lambda id=item_id: self.remove_from_order(id))
                delete_btn.pack(side=tk.RIGHT, padx=5)
        
        # 计算服务费和总计
        service_fee = subtotal * 0.10
        total = subtotal + service_fee
        
        # 更新显示
        self.subtotal_label.config(text=f"小计: ¥{subtotal:.2f}")
        self.service_label.config(text=f"服务费(10%): ¥{service_fee:.2f}")
        self.total_label.config(text=f"总计: ¥{total:.2f}")
    
    def remove_from_order(self, item_id):
        """从订单中移除菜品"""
        if item_id in self.current_order:
            self.current_order[item_id]['quantity'] = 0
            
            # 更新数量显示
            if 'label' in self.current_order[item_id]:
                self.current_order[item_id]['label'].config(text="0")
            
            # 重新显示当前类别的菜品（以更新数量显示）
            current_category = None
            for cat, btn in self.category_buttons.items():
                if btn.cget('bg') == '#d32f2f':  # 当前选中的类别
                    current_category = cat
                    break
            
            if current_category:
                self.show_category_items(current_category)
            
            # 更新订单显示
            self.update_order_display()
    
    def clear_order(self):
        """清除当前订单"""
        if not self.current_order or all(item['quantity'] == 0 for item in self.current_order.values()):
            messagebox.showinfo("提示", "当前订单为空")
            return
        
        if messagebox.askyesno("确认", "确定要清除当前订单吗？"):
            # 重置所有数量为0
            for item_id in self.current_order:
                self.current_order[item_id]['quantity'] = 0
                
                # 更新数量显示
                if 'label' in self.current_order[item_id]:
                    self.current_order[item_id]['label'].config(text="0")
            
            # 重新显示当前类别的菜品
            current_category = None
            for cat, btn in self.category_buttons.items():
                if btn.cget('bg') == '#d32f2f':
                    current_category = cat
                    break
            
            if current_category:
                self.show_category_items(current_category)
            
            # 更新订单显示
            self.update_order_display()
            
            messagebox.showinfo("成功", "订单已清除")
    
    def submit_order(self):
        """提交订单"""
        # 检查是否有菜品
        has_items = False
        for item_info in self.current_order.values():
            if item_info.get('quantity', 0) > 0:
                has_items = True
                break
        
        if not has_items:
            messagebox.showwarning("警告", "请先添加菜品到订单")
            return
        
        # 获取桌号
        try:
            table_num = int(self.table_var.get())
            if table_num < 1 or table_num > 50:
                raise ValueError
        except:
            messagebox.showerror("错误", "请输入有效的桌号（1-50）")
            return
        
        # 计算金额
        subtotal = 0
        order_items = []
        
        for item_id, item_info in self.current_order.items():
            quantity = item_info.get('quantity', 0)
            if quantity > 0:
                name = item_info.get('name', '未知菜品')
                price = item_info.get('price', 0)
                item_total = quantity * price
                subtotal += item_total
                
                order_items.append({
                    'id': item_id,
                    'name': name,
                    'price': price,
                    'quantity': quantity,
                    'total': item_total
                })
        
        service_fee = subtotal * 0.10
        total = subtotal + service_fee
        
        # 创建订单记录
        order_record = {
            'order_id': self.order_number,
            'table_number': table_num,
            'order_time': datetime.now().strftime("%Y-%m-%d %H:%M:%S"),
            'items': order_items,
            'subtotal': subtotal,
            'service_fee': service_fee,
            'total': total,
            'status': '已提交'
        }
        
        # 添加到历史记录
        self.order_history.append(order_record)
        
        # 生成订单确认信息
        order_summary = f"""
        ========== 订单确认 ==========
        订单号: #{self.order_number:04d}
        桌号: {table_num}
        时间: {order_record['order_time']}
        
        订单详情:
        """
        
        for item in order_items:
            order_summary += f"  {item['name']} × {item['quantity']} = ¥{item['total']:.2f}\n"
        
        order_summary += f"""
        小计: ¥{subtotal:.2f}
        服务费: ¥{service_fee:.2f}
        总计: ¥{total:.2f}
        
        状态: 已提交
        =============================
        """
        
        # 显示订单确认
        messagebox.showinfo("订单提交成功", order_summary)
        
        # 清空当前订单
        self.clear_order()
        
        # 生成新订单号
        self.order_number += 1
        self.order_num_label.config(text=f"订单号: #{self.order_number:04d}")
        
        # 保存历史记录
        self.save_order_history()
    
    def show_order_history(self):
        """显示历史订单"""
        history_window = tk.Toplevel(self.window)
        history_window.title("历史订单")
        history_window.geometry("800x600")
        history_window.configure(bg="#f0f0f0")
        
        # 标题
        title_label = tk.Label(history_window, text="历史订单记录", 
                              font=("微软雅黑", 18, "bold"), 
                              bg="#f0f0f0", fg="#333333")
        title_label.pack(pady=10)
        
        # 创建文本框显示历史订单
        history_text = scrolledtext.ScrolledText(history_window, 
                                                font=("微软雅黑", 10),
                                                width=90, height=30)
        history_text.pack(padx=10, pady=10, fill=tk.BOTH, expand=True)
        
        # 添加历史订单内容
        if not self.order_history:
            history_text.insert(tk.END, "暂无历史订单记录")
        else:
            for i, order in enumerate(reversed(self.order_history), 1):
                history_text.insert(tk.END, f"{i}. 订单号: #{order['order_id']:04d}\n")
                history_text.insert(tk.END, f"   桌号: {order['table_number']}\n")
                history_text.insert(tk.END, f"   时间: {order['order_time']}\n")
                history_text.insert(tk.END, f"   总计: ¥{order['total']:.2f}\n")
                history_text.insert(tk.END, f"   状态: {order['status']}\n")
                
                # 显示菜品
                for item in order['items']:
                    history_text.insert(tk.END, f"     - {item['name']} × {item['quantity']}\n")
                
                history_text.insert(tk.END, "-" * 60 + "\n\n")
        
        history_text.config(state=tk.DISABLED)
        
        # 关闭按钮
        close_btn = tk.Button(history_window, text="关闭", 
                             font=("微软雅黑", 11),
                             bg="#d32f2f", fg="white",
                             padx=20, pady=5,
                             command=history_window.destroy)
        close_btn.pack(pady=(0, 10))
    
    def on_closing(self):
        """窗口关闭事件处理"""
        self.save_order_history()
        self.window.destroy()
    
    def run(self):
        """运行程序"""
        self.window.mainloop()

def main():
    """主函数"""
    app = RestaurantOrderSystem()
    app.run()

if __name__ == "__main__":
    main()