package cipher

import (
	"strings"
)

type Cipher interface {
	Encode(string) string
	Decode(string) string
}

func (c CeasarCipherer) Encode (s string) string {
  s = strip(s)
  runes := []rune(s)
  var newRune rune
  for i, v := range string(s) {
	newRune = v + 3
	runes[i] = getShiftedRune(newRune)
  }
  return string(runes)
}

func (c CeasarCipherer) Decode(s string) string {
	s = strip(s)
	runes := []rune(s)
	var newRune rune
  for i, v := range string(s) {
	newRune = v - 3
	runes[i] = getShiftedRune(newRune)
  }
	return string(runes)
}

func (c ShiftCipherer) Encode(s string) string {
  s = strip(s)
  runes := []rune(s)
  var newRune rune
  for i, v := range string(s) {
	newRune = v + rune(c.shift)
	runes[i] = getShiftedRune(newRune)
  }
  return string(runes)
}

func (c ShiftCipherer) Decode(s string) string {
	s = strip(s)
	runes := []rune(s)
	var newRune rune
  for i, v := range string(s) {
	newRune = v - rune(c.shift)
	runes[i] = getShiftedRune(newRune)
  	}
	return string(runes)
}

func (c VigenereCipherer) Encode(s string) string {
  s = strip(s)
  runes := []rune(s)
  var newRune rune
  for i, v := range string(s) {
	newRune = v + rune(c.shiftStr[i % len(c.shiftStr)]) - 'a'
	runes[i] = getShiftedRune(newRune)
  }
  return string(runes)
}

func (c VigenereCipherer) Decode(s string) string {
	s = strip(s)
	runes := []rune(s)
	var newRune rune
  for i, v := range string(s) {
	newRune = v - (rune(c.shiftStr[i % len(c.shiftStr)]) - 'a')
	runes[i] = getShiftedRune(newRune)
  	}
	return string(runes)
}

type CeasarCipherer struct {}

type ShiftCipherer struct {
	shift int
}

type VigenereCipherer struct {
	shiftStr string
}

func NewCaesar() Cipher {
	return CeasarCipherer {}
}

func NewShift(i int) Cipher {
	if i < -25 || i > 25 || i == 0 {
		return nil
	}
	return ShiftCipherer {i}
}

func NewVigenere(s string) Cipher {
	if (len(s) == 0) {
		return nil
	}
	var allA bool = true
	for _, v := range s {
		if v <= 94 || v >= 123 {
			return nil
		}
		if v != 'a' {
			allA = false
		}
	}

	if (allA) {
		return nil
	}

	return VigenereCipherer {s}
}

func strip(s string) string {
  var str []rune
  for i, v := range s {
	  if (v >= 65 && v <= 90) || (v >= 97 && v <= 122) {
		  str = append(str, v)
	  } else {
		  i--
	  }
  }
  s = strings.ToLower(string(str))
  return s
}

func getShiftedRune(r rune) rune {
	if r >= 97 && r <= 122 {
		return r
	} else if (r >= 71 && r <= 96) {
		return 122 - (96 - r)
	} else if (r >= 123 && r <= 148) {
		return 97 + r - 123
	}
	return 0
}
