import numpy as np
import matplotlib.pyplot as plt

# datファイルの読み込み（例: 空白区切り）
data = np.loadtxt('../Output/phi.dat')  # または 'data.txt' など

x = data[:, 0]
y = data[:, 1]
phi = data[:, 2]

# 不規則格子の場合（点がグリッド状でない場合）
plt.tricontourf(x, y, phi, levels=50, cmap='viridis')
plt.colorbar(label='Scalar Potential φ')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Contour plot of φ')
plt.tight_layout()
plt.show()
