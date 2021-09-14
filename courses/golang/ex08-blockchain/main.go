package main

import (
	"fmt"
	"strconv"
)

func main() {
	bc := NewBlockchain()
	bc.AddBlock("Send 1 BTC to Ivan")
	bc.AddBlock("Send 2 BTC to Ivan")

	for _, v := range bc.blocks {
		fmt.Printf("PrevBlockHash: %x\n", v.PrevBlockHash)
		fmt.Printf("Hash: %x\n", v.Hash)
		fmt.Printf("Data: %s\n", v.Data)
		pow := NewProofOfWork(v)
		fmt.Printf("PoW: %s\n", strconv.FormatBool(pow.Validate()))
		fmt.Println("----------")
	}
}

func IntToHex(i int64) []byte {
	return []byte(strconv.FormatInt(i, 16))
}
