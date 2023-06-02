#include <iostream>
#include <cstring>

const int len(const char*);

char* GetVideIDFromURL(const char*);

int main(int argc, char** argv) {
    char* videoID = GetVideIDFromURL("https://youtu.be/r55_hiiN520");

    std::cout << "Video ID: ";
    std::cout << videoID << '\n';

    // free allocated memory
    delete[] videoID;
}

const int len(const char* str) {
    int len{ 0 };
    while (*str++)
        len++;
    return len;
}

char* GetVideIDFromURL(const char* url) {
    const int urlLenght = strlen(url);

    // https://youtu.be/r55_hiiN520
    int index = urlLenght;
    while (url[index] != '/')
        index--;

    char* id = new char[urlLenght - index + 1];

    for (int k = 0, i = index + 1; i < urlLenght; i++)
        id[k++] = url[i];
    return id;
}