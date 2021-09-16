package main

import (
	"fmt"
	"net"
	"bufio"
	"os"
	"strconv"
	"encoding/json"
	"math/big"
)

func main() {
	conn, err := net.Dial("tcp", ":8081")
	if err != nil {
		panic(err)
	}

	defer conn.Close()

	for {
		reader := bufio.NewReader(os.Stdin)
		fmt.Print("Data to send: ")
		text, _ := reader.ReadString('\n')
		fmt.Fprintf(conn, getJsonToSend(text) +"\n")

		message, _ := bufio.NewReader(conn).ReadString('\n')
		response := parseJsonResponse(message)
		fmt.Println(response.String())
	}

}

func parseJsonResponse(str string) big.Int {
	data := make(map[string][]byte)
	json.Unmarshal([]byte(str), &data)
	big := &BigInt { *big.NewInt(0) }
	big.UnmarshalJSON(data["number"])
	return big.Int
}

func getJsonToSend(input string) string {
	number, err := strconv.Atoi(input[:len(input) - 1])
	if err != nil {
		panic(err)
	}

	data, _ := json.Marshal(map[string]int {"number" : number})
	return string(data)
}

func (b *BigInt) UnmarshalJSON(p []byte) error {
    if string(p) == "null" {
        return nil
    }
    var z big.Int
    _, ok := z.SetString(string(p), 10)
    if !ok {
        return fmt.Errorf("not a valid big integer: %s", p)
    }
    b.Int = z
    return nil
}


type BigInt struct {
    big.Int
}