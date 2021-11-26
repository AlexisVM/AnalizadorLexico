##
#Alexis Vázquez
#Compiladores
#Analizador Léxico
##

#Initialize arrays to be used
productions = []
headers = []
terminals = []

#Function to get non terminals or headers
def getHeaders():
    for i in range(0, len(productions)):
        #split the array into it's elements to obtain separate productions
        prod = productions[i].split()
        #check if the first element in the production is already a header, if not, add it to the list
        if prod[0] not in headers:
            headers.append(prod[0])

#Function to get terminals
def getTerminals():
    for i in range(0, len(productions)):
        #split the array into it's elements to obtain separate productions
        prod = productions[i].split()
        #another for loop iterates over the separated productions to add unique values to the array, also ignoring the arrow
        for j in range(0, len(prod)):
            if prod[j] not in headers and prod[j] not in terminals and prod[j] != "->" and prod[j] != "'":
                terminals.append(prod[j])   

#Function to receive an input file if the option number 1 is selected
def lexicalAnalyzerConsoleFile():
    #input file name
    fileName = input("\nFilename: ")
    #open file and handle error if file doesn't exists
    try:
        OFile = open(fileName, "r")
    except:
        print("File not found")
    
    #Append the productions to the array "productions"
    for line in OFile:
        productions.append(line)
    
#Function to receive the productions from an input if option 2 is selected
def lexicalAnalyzerConsoleCMD():
    amount = int(input("\nHow many productions are? "))
    
    #Appending the input to the productions while reading them
    for i in range(0, amount):
        productions.append(input())


# Main Function
def main():
    #Usage options
    print("Lexical Analyzer\n")
    print("There are two ways of using the analyzer, from file and from command line")
    option = input("Select the option: (1. From file, 2. From command line.) ")
    if option == "1": 
        lexicalAnalyzerConsoleFile()
    else:
        lexicalAnalyzerConsoleCMD()

    #Execute the functions to find elements
    getHeaders()
    getTerminals()

#Execute Main function
main()

#Print formatted elements
print("Terminal: " + ", ".join(terminals))
print("Non terminal: " + ", ".join(headers))