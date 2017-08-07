// Написать программу на любом языке, которая считает количество строк в заданном файле.
// Имя файла задается в командной строке. Считать, что строки разделяются `\n`.
// Кол-во строк вывести в stdout. Результирующая программа будет аналогична вызову `wc -l /path/to/file`.
// Исходный код выложить на github и прислать ссылку.

package main

import (
	"os"
	"fmt"
	"bufio"
	"io"
	"log"
)

func main() {
	if len(os.Args) != 2 {
		log.Fatal("Enter the file path!")
	}
	file_path := os.Args[1]
	file, err := os.Open(file_path)
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	scanner := bufio.NewReader(file)
	number_of_lines := 0
	for {
		_, err := scanner.ReadString('\n')
		if err == io.EOF {
			break
		}
		if err != nil {
			file.Close()
			log.Fatal(err)
		}
		number_of_lines++
	}

	fmt.Println(number_of_lines, file_path)
	return
}
