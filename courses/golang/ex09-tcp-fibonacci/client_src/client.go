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
	conn, err := net.Dial("tcp", ":8080")
	if err != nil {
		panic(err)
	}

	defer conn.Close()

	for {
		reader := bufio.NewReader(os.Stdin)
		text, _ := reader.ReadString('\n')
		if len(text) == 0 {
			break
		}
		fmt.Fprintf(conn, getJsonToSend(text) +"\n")

		message, _ := bufio.NewReader(conn).ReadString('\n')
		time, num := parseJsonResponse(message)
		fmt.Println(time + " " + num.String())
	}

}

func parseJsonResponse(str string) ( string, big.Int) {
	data := make(map[string][]byte)
	json.Unmarshal([]byte(str), &data)
	big := &BigInt { *big.NewInt(0) }
	big.UnmarshalJSON(data["number"])
	return string(data["time"]), big.Int
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