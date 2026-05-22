# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn.datasets import make_blobs
import matplotlib.patches as mpatches

# 设置中文字体支持
plt.rcParams['font.sans-serif'] = ['SimHei', 'Microsoft YaHei', 'DejaVu Sans']
plt.rcParams['axes.unicode_minus'] = False

# 1. 生成模拟数据集 - 减少元素数量
n_clusters = 4

# 左图：Canopy聚类数据 - 聚集点再向中心靠近一点
n_samples_left = 120
# 从(±2.2, ±2.2)调整为(±2.0, ±2.0)，更靠近中心
centers_left = np.array([[2.0, 2.0], [2.0, -2.0], [-2.0, 2.0], [-2.0, -2.0]])
X_left, y_left = make_blobs(n_samples=n_samples_left, 
                            centers=centers_left,
                            cluster_std=[0.5, 0.5, 0.5, 0.5],
                            random_state=42)

# 右图：K-means聚类数据 - 保持原样
n_samples_right = 80
centers_right = np.array([[1.5, 1.5], [1.5, -1.5], [-1.5, 1.5], [-1.5, -1.5]])
X_right, y_right = make_blobs(n_samples=n_samples_right, 
                              centers=centers_right,
                              cluster_std=[0.6, 0.6, 0.6, 0.6],
                              random_state=42)

# 2. 创建图形
fig, axes = plt.subplots(1, 2, figsize=(14, 7))

# 颜色和标记设置
colors = ['cyan', 'gold', 'red', 'green']
markers = ['^', '*', 'd', 'v']
marker_sizes_left = [22, 22, 22, 22]
marker_sizes_right = [25, 25, 25, 25]

# 3. 左图: Canopy聚类效果图
ax1 = axes[0]

# 调整四个角的半径
T1 = 2.8
T2 = 1.6

# 绘制四个角的数据点
for i, center in enumerate(centers_left):
    # 绘制数据点
    cluster_points = X_left[y_left == i]
    ax1.scatter(cluster_points[:, 0], cluster_points[:, 1], 
                c=colors[i], marker=markers[i], s=marker_sizes_left[i],
                edgecolors='none', alpha=0.85, zorder=5, label=f'Cluster {i+1}')
    
    # 绘制内圈（红色实线）
    circle_t2 = mpatches.Circle(center, T2, 
                                fill=False, 
                                edgecolor='red',
                                linewidth=1.8,
                                linestyle='-',
                                alpha=0.9)
    ax1.add_patch(circle_t2)
    
    # 绘制外圈（蓝色虚线）
    circle_t1 = mpatches.Circle(center, T1, 
                                fill=False, 
                                edgecolor='blue',
                                linewidth=1.4,
                                linestyle='--',
                                alpha=0.8)
    ax1.add_patch(circle_t1)
    
    # 绘制内聚点（黑色"+"号）
    ax1.scatter(center[0], center[1], 
                c='black', marker='+', s=180, linewidth=2.2, 
                zorder=6)

# 设置左图标题和坐标轴
ax1.set_xlabel('X', fontsize=12)
ax1.set_ylabel('Y', fontsize=12)
ax1.set_title('图8 canopy 聚类效果图', fontsize=14, fontweight='bold')
ax1.grid(True, alpha=0.3, linewidth=0.6)

# 缩小坐标轴范围，使聚集点更靠近中心
axis_limit = 5.0  # 从5.5调整为5.0
ax1.set_xlim(-axis_limit, axis_limit)
ax1.set_ylim(-axis_limit, axis_limit)
ax1.set_aspect('equal', 'box')
ax1.tick_params(axis='both', which='major', labelsize=11)

# 4. 右图: K-means聚类效果图
ax2 = axes[1]

# 应用K-means聚类
kmeans = KMeans(n_clusters=n_clusters, 
                init=centers_right,
                n_init=1,
                random_state=42)
kmeans_labels = kmeans.fit_predict(X_right)
kmeans_centers = kmeans.cluster_centers_

# 为每个簇绘制数据点
for i in range(n_clusters):
    cluster_points = X_right[kmeans_labels == i]
    ax2.scatter(cluster_points[:, 0], cluster_points[:, 1], 
                c=colors[i], marker=markers[i], s=marker_sizes_right[i],
                edgecolors='none', alpha=0.85, zorder=2, label=f'Cluster {i+1}')

# 绘制K-means中心点（黑色"+"号）
ax2.scatter(kmeans_centers[:, 0], kmeans_centers[:, 1], 
            c='black', marker='+', s=180, linewidth=2.2, 
            zorder=5)

# 设置右图标题和坐标轴
ax2.set_xlabel('X', fontsize=12)
ax2.set_ylabel('Y', fontsize=12)
ax2.set_title('图8 k-means 聚类效果图', fontsize=14, fontweight='bold')
ax2.grid(True, alpha=0.3, linewidth=0.6)
ax2.set_xlim(-4, 4)
ax2.set_ylim(-4, 4)
ax2.set_aspect('equal', 'box')
ax2.tick_params(axis='both', which='major', labelsize=11)

# 5. 添加图例
from matplotlib.lines import Line2D

# 创建统一的图例元素
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

# 左图添加额外的圆圈图例
legend_elements_left = legend_elements + [
    Line2D([0], [0], color='red', lw=1.8, label='内阈半径 (红色实线)'),
    Line2D([0], [0], color='blue', lw=1.4, linestyle='--', label='外阈半径 (蓝色虚线)')
]

ax1.legend(handles=legend_elements_left, loc='upper right', fontsize=10, framealpha=0.9)
ax2.legend(handles=legend_elements, loc='upper right', fontsize=10, framealpha=0.9)

# 6. 调整布局和显示
plt.tight_layout()

# 保存图片
plt.savefig('聚类算法效果对比_聚集点更靠近中心.png', dpi=350, bbox_inches='tight', 
            facecolor='white', edgecolor='none')
print("图片已保存为 '聚类算法效果对比_聚集点更靠近中心.png'")
print("\n调整说明：")
print("1. 左图四个聚集点从(±2.2, ±2.2)调整为(±2.0, ±2.0)，更靠近中心")
print("2. 左图坐标轴范围从(-5.5,5.5)调整为(-5.0,5.0)")
print("3. 聚集点距离原点: √(2.0²+2.0²) ≈ 2.83 单位")
print("4. 右图所有参数保持不变")

plt.show()

# 7. 输出详细的对比信息
print("\n=== 聚类算法对比 ===")
print(f"左图元素数量: {n_samples_left} 个点")
print(f"右图元素数量: {n_samples_right} 个点")
print(f"簇数量: {n_clusters}")

print("\nCanopy聚类 (左图) - 聚集点更靠近中心:")
for i, (center, color, marker) in enumerate(zip(centers_left, colors, markers)):
    cluster_size = np.sum(y_left == i)
    distance_to_center = np.sqrt(center[0]**2 + center[1]**2)
    print(f"  {color} {marker}: {cluster_size} 个点")
    print(f"    中心位置: ({center[0]:.1f}, {center[1]:.1f})")
    print(f"    距离原点: {distance_to_center:.2f} 单位")

print("\nK-means聚类 (右图):")
for i, (center, color, marker) in enumerate(zip(kmeans_centers, colors, markers)):
    cluster_size = np.sum(kmeans_labels == i)
    print(f"  {color} {marker}: {cluster_size} 个点, 中心: ({center[0]:.2f}, {center[1]:.2f})")