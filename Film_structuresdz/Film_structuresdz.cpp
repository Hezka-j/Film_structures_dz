#include <iostream>
#include<ctime>
using namespace std;
struct Film {
    string name_film;
    string genre[2];
    double rate[4];
    string surname;
    string names;
    
    const char* names_film[4] = { "Ice Kings", "Gran Turismo", "Five nights at freddy's", "Sherlock Holmes" };
    
    string genres[6] = { "Komedy", "Sport", "Adventure", "Horror", "Mystery", "Detective" };
    
    string surnames[4] = { "Tessier", "Blomkamp", "Tammy", "Kavun" };
    string names2[4] = { "Eric", "Neill", "Emma", "Andrey" };
};
void GenerateFilm(Film& search, short numb)
{
    //search.names_film[] = { "Ice Kings", "Gran Turismo", "Five nights at freddy's", "Sherlock Holmes" };
    
    
    bool ok = false;
    for (int i = 0; i < 4; i++)
    {
        
        if (ok)
        {
            break;
        }
        switch (numb)
        {
        case 0:
        {
            search.name_film = search.names_film[numb];
            if (numb == 0)
            {
                search.genre[i] = search.genres[numb];
                search.genre[i + 1] = search.genres[numb + 1];
            }
            search.rate[numb] = rand() % 60 / 10;
            search.surname = search.surnames[numb];
            search.names = search.names2[numb];
            ok = true;
            break;
        }
        case 1:
        {
            search.name_film = search.names_film[numb];
            if (numb == 1)
            {
                search.genre[i] = search.genres[numb];
                search.genre[i + 1] = search.genres[numb + 1];
            }
            search.rate[numb] = rand() % 60 / 10;
            search.surname = search.surnames[numb];
            search.names = search.names2[numb];
            ok = true;
            break;
        }
        case 2:
        {
            search.name_film = search.names_film[numb];
            if (numb == 2)
            {
                search.genre[i] = search.genres[numb + 1];
                search.genre[i + 1] = search.genres[numb + 2];
            }
            search.rate[numb] = rand() % 60 / 10;
            search.surname = search.surnames[numb];
            search.names = search.names2[numb];
            ok = true;
            break;
        }
        case 3:
        {
            search.name_film = search.names_film[numb];
            if (numb == 3)
            {
                
                search.genre[i] = search.genres[numb + 2];
            }
            search.rate[numb] = rand() % 60 / 10;
            search.surname = search.surnames[numb];
            search.names = search.names2[numb];
            ok = true;
            break;
        }
        }
    }
}
void PrintFilm(Film& search, short numb)
{
    cout << "Film: " << search.name_film << "\n";
    cout << "Genres: ";
    for(int i = 0; i < 2; i++)
    {
        
        cout << search.genre[i] << " ";
    }
    cout << "\n";
    cout << "Rate: " << search.rate[numb] << "\n";
    cout << "Director: " << search.names << " " << search.surname << "\n";
}
void SearchFilm(Film& search, short numb)
{
    char* input = new char[100];
    bool ok = false;
    cout << "Film to search - ";
    gets_s(input, 100);
    
    cout << "Your film -> ";
    for(int i = 0; i < 4; i++)
    {

        /*for(int j = 0; j < strlen(search.names_film[i]); j++)
        {*/
           if (_strcmpi(input, search.names_film[i]) == 0)
            {
               ok = true;
                cout  << search.names_film[i];
            }
           /*}*/if (!ok) 
                    break;
    }
    if (!ok)
    {
        cout << "Film nor found\n";
        return;
    }
    cout << "\n";
    cout << "Genres: ";
    for(int i = 0; i < 2; i++)
    {

        cout << search.genre[i] << " ";
    }
    cout << "\n";
    cout << "Rate: " << search.rate[numb] << "\n";
    cout << "Director: " << search.names << " " << search.surname << "\n";
    
}
int main()
{
    srand(time(0));
    Film search;
    short numb = rand() % 4;
    GenerateFilm(search, numb);
    PrintFilm(search, numb);
    SearchFilm(search, numb);
    //delete[] search.names_film;
}