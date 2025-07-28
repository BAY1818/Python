import random


class Song:
    def __init__(self,title,artist):
        self.title = title
        self.artist = artist

class Playlist:
    def __init__(self):
        self.songs = []
    def add_song(self,song):
        if isinstance(song,Song):
            self.songs.append(song)
            print(f"Song {song.title} added to Playlist.")
    def remove_song(self,title):
        for song in self.songs:
            if song.title == title:
                self.songs.remove(song)
                return f"Song {song.title} {song.artist} removed from Playlist."
            else:
                return f"Song {song.title} {song.name} was not found!!!"
    def play_next(self,song):
        if song in self.songs:
            index = self.songs.index(song)
            if index < len(self.songs) - 1:
                return self.songs[index+1].title
            else:
                return f"Last song on Playlist!!!"
        else:
            return f"Playlist is emtpy!!!"
    def shuffle_song(self):
        random.shuffle(self.songs)
        return f"Playlist is shuffled!"
    def show_playlist(self):
        for song in self.songs:
            print( f"{song.title} {song.artist}")


song1 = Song("Mansion" , "NF")
song2 = Song("Babysitter" , "Jack Coy")
song3 = Song("Let you down" , "NF")

playlist = Playlist()

playlist.add_song(song1)
playlist.add_song(song2)
playlist.add_song(song3)
playlist.show_playlist()
print(playlist.play_next(song2))
print(playlist.shuffle_song())
print(playlist.remove_song("Babysitter"))