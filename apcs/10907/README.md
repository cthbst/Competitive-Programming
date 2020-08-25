# APCS 109/07/04 by cthbst

## pA
- 用 std::map 或是一個範圍至少有 100 的陣列，記錄每一種數字的出現次數
- time: O(100 * T + length) 

## pB
- 用 struct 儲存每一面目前的點數
- 每次修改操作直接呼叫對應的修改函式
- time: O(n + m)

## pC
- 對於每個查詢 qi, 先把 qi mod 環狀陣列的總和，最後用 binary search 找到下一個開始的位置
- time: O(n + m log n)

## pD
- 每一個位數是獨立的，因此可以把 1 個字串長度為 m 的問題想成 m 個字串長度都是 1 的問題
- 使用樹形動態規劃(Dynamic Programming)
	- 定義狀態 dp(u, i) = 以 u 為根的子樹中，根的字母是 i 的答案
	- 狀態轉移 dp(u, i) = \sum{ dp(v, j) + (i!=j) : v 是 u 的小孩 }
- time: O(n * m * 26 * 26)
	
