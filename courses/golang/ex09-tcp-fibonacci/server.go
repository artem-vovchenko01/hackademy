package main

import (
	"encoding/json"
	"net"
	"bufio"
	"math/big"
)

func main(){
	ln, err := net.Listen("tcp", ":8081")
	if err != nil {
		panic(err)
	}
	defer ln.Close()

	conn, err := ln.Accept()
	defer conn.Close()
	for {
		if err != nil {
			panic(err)
		}
		mesg, _ := bufio.NewReader(conn).ReadString('\n')
		conn.Write([]byte(getJsonToSend(mesg) + "\n"))
	} 
}

func getJsonToSend(str string) string {
	mesg := make(map[string]int)
	send := make(map[string][]byte)
	json.Unmarshal([]byte(str), &mesg)
	res := big.NewInt(int64(mesg["number"]))
	bigNum, _ := BigInt { fibo(*res), }.MarshalJSON()
	send["number"] = bigNum
	bytes, _ := json.Marshal(send)
	return string(bytes)
}

func fibo(num big.Int) big.Int {
	zero := big.NewInt(0)
	one := big.NewInt(1)
	a := big.NewInt(0)
	b := big.NewInt(1)
	for num.Cmp(zero) == 1 {
		a.Add(a, b)
		a, b = b, a
		num.Sub(&num, one)
	}
	return *a
}

func (b BigInt) MarshalJSON() ([]byte, error) {
    return []byte(b.String()), nil
}

type BigInt struct {
    big.Int
}