package main

import (
	"fmt"
	"bytes"
	"crypto/sha256"
	"strconv"
	"time"
)

type Block struct {
	timestamp int64
	Data			[]byte
	PrevBlockHash 	[]byte
	Hash			[]byte
}

func (b *Block) SetHash() {
	timestamp := []byte(strconv.FormatInt(b.timestamp, 10))
	headers := bytes.Join([][]byte{b.PrevBlockHash, b.Data, timestamp}, []byte {})
	hash := sha256.Sum256(headers)
	b.Hash = hash[:]
}

func NewBlock(data string, prevBlockHash []byte ) *Block {
	block := &Block {time.Now().Unix(), []byte(data), prevBlockHash, []byte{} }
	block.SetHash()
	return block
}

type Blockchain struct {
	blocks []*Block
}

func (bc *Blockchain) AddBlock(data string) *Block {
	prevBlock := bc.blocks[len(bc.blocks) - 1]
	newBlock := NewBlock(data, prevBlock.Hash)
	bc.blocks = append(bc.blocks, newBlock)
	return newBlock
}

func NewGenesisBlock() *Block {
	return NewBlock("Genesis block", []byte{})
}

func NewBlockchain() *Blockchain {
	return &Blockchain{[]*Block{NewGenesisBlock()}}
}

func main() {
	bc := NewBlockchain()
	bc.AddBlock("Send 1 BTC to Ivan")
	bc.AddBlock("Send 2 BTC to Ivan")

	for _, v := range bc.blocks {
		fmt.Printf("PrevBlockHash: %x\n", v.PrevBlockHash)
		fmt.Printf("Hash: %x\n", v.Hash)
		fmt.Printf("Data: %s\n", v.Data)
		fmt.Println("----------")
	}
}