class Deck(object):
    
    def __init__(self):
        self.d = list()



def tt(deck : Deck):
    print(deck.d)

    deck.d+=[2,2]


de = Deck()
de.d = [1,2,3]

tt(de)

print(de.d)