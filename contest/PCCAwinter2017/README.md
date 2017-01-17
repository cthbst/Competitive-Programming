- 活動網址
	- https://sites.google.com/view/nctupcca
- 上課影片
	-　https://drive.google.com/drive/folders/0B4_aol7uG4_YSEp2Q3dMVVM3WFk
# Day1 組合賽局理論
- Nim SG 
	- SG(u) = mex{　SG(v)　|　v是u的後繼狀態　}
	- SG(u+v) = SG(u) XOR SG(v)
- surreal number (日本賽區新形賽局題目)
	- 難難的看不懂

# Day2 Flow & 圖論相相關定理
- max flow
	- |max flow| = |min cut|
	- cut 可以處理要取或不取的問題
	-　要時進將節點上的東西移動的問題可以轉成前後歷史的兩接階層流
- 圖論相關定理
	-　(一般圖)　max IS + min VC = V
	- (一般圖) | max matching | + | min EC | = |V|
	- (二分圖) | max mathcing | = | max flow |
	- (二分圖) | max matching | = | min VC|
	- (二分圖) | min EC | + | min VC | = |V|
- 流相關題目
	- 形容詞 : Bipartite, Weighted, Min-cost
	- 主詞 : Matching, Vertex Cover, Edge Cover, Flow/Cuts
	- 2^|形容詞|　*　|主詞|　= 32種變型
	- 穩定婚姻
