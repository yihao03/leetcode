package leetcode

func getProductSuggestions(products []string, search string) [][]string {
	// Write your code here
	result := make([][]string, len(search))
	for i := 0; i < len(search); i++ {
		str := search[:i+1]
		this := make([]string, 0, len(products))
		for _, product := range products {
			if product[:i+1] == str {
				this = append(this, product)
			}
		}
		result = append(result, this)
	}

	return result
}
