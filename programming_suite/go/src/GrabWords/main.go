package main

import (
    "bufio"
    "fmt"
    "io/ioutil"
    "net/http"
    "os"
    "regexp"
  
)

func main() {
    // Check if the correct number of command-line arguments is provided
    if len(os.Args) != 2 {
        fmt.Println("Usage: go run main.go <URL>")
        return
    }

    // Get the URL from command-line arguments
    url := os.Args[1]

    // Fetch the content of the URL
    resp, err := http.Get(url)
    if err != nil {
        fmt.Println("Error fetching URL:", err)
        return
    }
    defer resp.Body.Close()

    // Read the response body
    body, err := ioutil.ReadAll(resp.Body)
    if err != nil {
        fmt.Println("Error reading response body:", err)
        return
    }

    // Convert the body bytes to string
    bodyString := string(body)

    // Use regular expression to find all words
    re := regexp.MustCompile(`\b\w+\b`)
    words := re.FindAllString(bodyString, -1)

    // Create or open the output file
    file, err := os.Create("words.txt")
    if err != nil {
        fmt.Println("Error creating file:", err)
        return
    }
    defer file.Close()

    // Write words to the file
    writer := bufio.NewWriter(file)
    for _, word := range words {
        _, err := writer.WriteString(word + "\n")
        if err != nil {
            fmt.Println("Error writing to file:", err)
            return
        }
    }

    // Flush any buffered data to ensure all data is written to the file
    err = writer.Flush()
    if err != nil {
        fmt.Println("Error flushing buffer:", err)
        return
    }

    fmt.Println("Words extracted and saved to words.txt successfully!")
}
