import random

def guess(x):
    random_number = random.randint(1,x)
    
    guess = 0;
    
    while (guess != random_number):
        guess = int(input(f'Guess a number between 1 and {x}: '))
        
        if guess < random_number:
            print('Sorry, guess again. Too low!')
        elif guess > random_number:
            print('Sorry, guess again. Too High!')
        
    print(f'Congrats! You guess the right number is {guess}!')
        
def computer_guess(x):
    low = 1
    high = x
    feedback = ''
    while feedback != 'c':
        if low != high: 
            guess = random.randint(low, high)
        else: 
            guess = low
        feedback = input(f'Is {guess} too high(H), too low(L), or correct (C)? ').lower()
        if feedback == 'h':
            high = guess - 1;
        elif feedback == 'l':
            low = guess + 1;
            
    print(f'Yay! The computer has found your number, {guess}, correctly!')
        
        
        


ans = int(input("Enter 1 if you want to guess or 2 if you want the computer to guess a number you have in mind: "))
num = int(input("Enter the maximum number in the range: "));

if ans == 1:
    guess(num)
elif ans == 2:
    computer_guess(num)
