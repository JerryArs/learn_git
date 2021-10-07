package main

import (
    "fmt"
    "net/http"
    "encoding/json"
)

func main() {
    http.HandleFunc("/", rootHandler)
    http.ListenAndServe(":80", nil)
}

func rootHandler(w http.ResponseWriter, r *http.Request) {
    headers := r.Header
    for key := range headers {
		value := r.Header.Get(key),
        w.Header().Add(key, value)
    }
    resp := make(map[string]string)
	resp["message"] = "success"
	jsonResp, _ := json.Marshal(resp)
	w.Write(jsonResp)
}