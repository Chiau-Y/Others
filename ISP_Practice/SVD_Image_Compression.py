import cv2
import numpy as np
import matplotlib.pyplot as plt

img_original = cv2.imread('D:/CHIAUYAUN/GitHub/test.jpg',0)    # 433*501

u, s, v = np.linalg.svd(img_original, full_matrices=True)

# --------------------------- 把s矩陣中的0刪除 -------------------------- #

s_temp = np.diag(s) # 對角化

v_compression_zero_delete = v[0:s.shape[0]][:]  # 壓縮

img_compression_zero_delete = (u.dot(s_temp)).dot(v_compression_zero_delete)


print("\n原圖矩陣元素個數 = {}".format(img_original.size))
print("把s矩陣中的0刪除後矩陣元素個數 = {} ".format(u.size + s_temp.size + v_compression_zero_delete .size))
print("壓縮率 = 	{:.2f}% ".format(100*(u.size + s_temp.size + v_compression_zero_delete .size)/img_original.size))

plt.figure(0)
plt.imshow(img_original, cmap='Greys_r') # 顯示圖片
plt.axis('off') # 不顯示座標軸
plt.figure(1)   # 與原圖沒有差別
plt.imshow(img_compression_zero_delete, cmap='Greys_r') # 顯示圖片
plt.axis('off') # 不顯示座標軸

# --------------------------- 影像壓縮 -------------------------- #

s_compression = np.diag(s[0:100])   # 留下[0:n]個特徵值，對角化
v_compression = v[0:s_compression.shape[0],:]  # 壓縮
u_compression = u[:,0:s_compression.shape[0]]  # 壓縮


img_compression = (u_compression.dot(s_compression)).dot(v_compression)


print("\n原圖矩陣元素個數 = {}".format(img_original.size))
print("影像壓縮後矩陣元素個數 = {} ".format(u_compression.size + s_compression.size + v_compression.size))
print("壓縮率 = 	{:.2f}% ".format(100*(u_compression.size + s_compression.size + v_compression.size)/img_original.size))

plt.figure(2)
plt.imshow(img_original, cmap='Greys_r') # 顯示圖片
plt.axis('off') # 不顯示座標軸
plt.figure(3)
plt.imshow(img_compression, cmap='Greys_r') # 顯示圖片
plt.axis('off') # 不顯示座標軸