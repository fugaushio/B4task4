import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import griddata
from mpl_toolkits.mplot3d import Axes3D

# データ読み込み
data = np.loadtxt("../Output/phi.dat") 
x = data[:, 0]
y = data[:, 1]
phi = data[:, 2]

# グリッドサイズを指定（細かくするほど滑らか）
grid_n = 10
xi = np.linspace(min(x), max(x), grid_n)
yi = np.linspace(min(y), max(y), grid_n)
X, Y = np.meshgrid(xi, yi)

# φを補間して格子状に変換
Z = griddata((x, y), phi, (X, Y), method='cubic')

# 3Dプロット
fig = plt.figure(figsize=(8, 6))
ax = fig.add_subplot(111, projection='3d')

# カラーマップ設定
vmin = 0.0
vmax = 1.0
surf = ax.plot_surface(X, Y, Z, cmap='viridis', edgecolor='none', vmin=vmin, vmax=vmax)

# 軸ラベル
ax.set_xlabel("X")
ax.set_ylabel("Y")
ax.set_zlabel("Phi")
ax.set_title("3D Surface Plot of Scalar Potential")

# カラーバーの追加
cbar = fig.colorbar(surf, ax=ax, shrink=0.6)
cbar.set_label("Phi")
cbar.set_ticks([vmin, vmax])

# 視点の調整（角度変更）
ax.view_init(elev=45, azim=-60)

plt.tight_layout()
plt.show()
