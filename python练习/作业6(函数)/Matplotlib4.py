import pylab as pl
import numpy as np

# 创建图形窗口，设置大小和分辨率
pl.figure(figsize=(8,6), dpi=100)  # 8英寸×6英寸，100dpi

t = np.arange(0., 4., 0.1)  # 创建从0到4的数组，步长0.1

# 第一条线：红色实线
pl.plot(t, t, 
        color='red',         # 线条颜色：红色
        linestyle='-',       # 线条样式：实线
        linewidth=3,         # 线宽：3
        label='Line1')       # 图例标签

# 第二条线：绿色，只有星号标记，没有线
pl.plot(t, t+2, 
        color='green',       # 颜色：绿色
        linestyle='',        # 线条样式：无（空字符串表示不画线）
        marker='*',          # 标记样式：星号
        linewidth=3,         # 线宽（这里实际不生效，因为没有线）
        label='Line2')       # 图例标签

# 第三条线：蓝色，只有加号标记，没有线
pl.plot(t, t**2, 
        color='blue',        # 颜色：蓝色
        linestyle='',        # 线条样式：无
        marker='+',          # 标记样式：加号
        linewidth=3,         # 线宽（这里实际不生效，因为没有线）
        label='Line3')       # 图例标签

# 显示图例，位置在左上角
pl.legend(loc='upper left')

# 显示图形
pl.show()