#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

enum genre{pop = 0, Jazz, Classic, HipHop};

struct album {
    string album_name;
    genre kind;
    int track_number;
    string tracks[5];
    string trackLocation;
};

struct album addAlbum(vector<album> albums) {
    int currentSize = albums.size();
    int count, temp;

    if (currentSize == 0) {
        count = currentSize;
    } else {
        count = currentSize + 1;
    }

    albums.resize(5);

    cout << "Enter album name: " << endl;
    cin >> albums[count].album_name;

    cout << "Enter genre (0 --> pop, 1 --> Jazz, 2 --> Classic, 3 --> Hip-Hop)" << endl;
    cin >> temp;
    albums[count].kind = static_cast<genre>(temp);

    cout << "Enter number of tracks in the album" << endl;
    cin >> albums[count].track_number;

    cout << "Enter the names for these " << albums[count].track_number << " tracks" << endl;
    for (int i = 0; i < albums[count].track_number; i++) {
        cin >> albums[count].tracks[i];
    }

    cout << "Enter the file location of these tracks: " << endl;
    cin >> albums[count].trackLocation;
 }

void printAlbums(vector<album> albums) {
    int albumSize = albums.size();
    cout << "There are currently " << albumSize << " album(s) stored." << endl;
}

int main()
{
    vector<album> albums;

    bool z = true;
    int menu;

    while(z) {
        cout << "1. Add an album" << endl;
        cout << "2. Print all albums" << endl;
        cout << "3. Play a track" << endl;
        cout << "4. Exit" << endl;

        cin >> menu;

        switch(menu) {
            case 1:
                addAlbum(albums);
                break;
            case 2:
                printAlbums(albums);
                break;
            case 3:
                cout << "Play Track" << endl;
                break;
            case 4:
                z = false;
                break;
        }

    }
    return 0;
}
