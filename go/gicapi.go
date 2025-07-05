package leetcode

import (
	"encoding/json"
	"fmt"
	"io"
	"net/http"
)

func energyBar(country string) string {
	data, err := readJson(country, 1)
	if err != nil {
		return err.Error()
	}
	fmt.Println("Data:", data)
	return "hi"
}

func readJson(country string, page int) (any, error) {

	url := fmt.Sprintf("https://jsonmock.hackerrank.com/api/chocolates?countryOfOrigin=%s&page=%d", country, page)
	res, err := http.Get(url)
	if err != nil {
		return nil, err
	}
	body, err := io.ReadAll(res.Body)
	if err != nil {
		return nil, err
	}

	var data any
	err = json.Unmarshal(body, &data)
	if err != nil {
		return nil, err
	}

	return data, nil
}
