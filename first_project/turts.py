import turtle
from  random import randint, sample
from time import sleep

odds = [-250, -200, -150, -100, -50, 50, 100, 150, 200, 250, 300]
assign_odds = sample(odds, 4)

real_odds = {
    "blue": assign_odds[0],
    "red" : assign_odds[1],
    "yellow": assign_odds[2],
    "purple": assign_odds[3]
}

tot_win_per = 0
per = 0

real_per = {}
for color in real_odds:
    if real_odds[color] > 0:
        per += 100 / (real_odds[color] + 100)
        tot_win_per += per
        real_per[color] = per
    else:
        per += abs(real_odds[color]) / (abs(real_odds[color]) + 100)
        tot_win_per += per
        real_per[color] = per

for color in real_per:
    real_per[color] = (real_per[color] / tot_win_per) * 100

for color in real_odds:
    real_odds[color] = round((100 - real_per[color]) / real_per[color]) * 100

assign_speed = {}
for color in real_per:
    assign_speed[color] = {color: (8 + round(real_per[color] / 10), (17 + (round(real_per[color]) / 10)))}

print("Gamble before we race our Turts!")
print("Odds:")
print(f"Red is {real_odds["red"]}")
print(f"Blue is {real_odds["blue"]}")
print(f"yellow is {real_odds["yellow"]}")
print(f"purple is {real_odds["purple"]}")

while True:
    bet = input("Who would you like to bet on?")
    if bet.lower() in real_odds:
        break
    else:
        print("bet on one of the colors")

while True:
    try:
        bet_amount = int(input("how much money would you like to bet?"))
        break
    except ValueError:
        print("Your bet must be a number")

print(f"${bet_amount} is on the line!!!")

window = turtle.Screen()
window.title('Turtle Race!')
window.bgcolor('lightgreen')

finline = 200
turtle.penup()
turtle.goto(finline, 100)
turtle.pendown()
turtle.right(90)
is_black = True
for i in range(2):
    for j in range(4):
        for k in range(4):
            turtle.color("white" if is_black else "black")
            turtle.forward(25)
            turtle.color("black" if is_black else "white")
            turtle.forward(25)
        turtle.left(90)
        turtle.forward(1)
        turtle.left(90)
        for k in range(4):
            turtle.color("black" if is_black else "white")
            turtle.forward(25)
            turtle.color("white" if is_black else "black")
            turtle.forward(25)
        turtle.right(90)
        turtle.forward(1)
        turtle.right(90)
    is_black = False

t1 = turtle.Turtle()
t2 = turtle.Turtle()
t3 = turtle.Turtle()
t4 = turtle.Turtle()

t1.color('blue')
t2.color('red')
t3.color('yellow')
t4.color('purple')

t1.shape('turtle')
t2.shape('turtle')
t3.shape('turtle')
t4.shape('turtle')

t1.penup()
t1.goto(20, 30)
t1.pencolor('blue')
t1.pendown()

t2.penup()
t2.goto(20, 10)
t2.pencolor('red')
t2.pendown()

t3.penup()
t3.goto(20, -10)
t3.pencolor('yellow')
t3.pendown()

t4.penup()
t4.goto(20, -30)
t4.pencolor('purple')
t4.pendown()

winner = "none"

while winner == "none":
    if t1.xcor() >= finline:
        winner = "blue"
    elif t2.xcor() >= finline:
        winner = "red"
    elif t3.xcor() >= finline:
        winner = "yellow"
    elif t4.xcor() >= finline:
        winner = "purple"

    t1.forward(randint(assign_speed["blue"][0], assign_speed["blue"][1]))
    t2.forward(randint(assign_speed["red"][0], assign_speed["red"][1]))
    t3.forward(randint(assign_speed["yellow"][0], assign_speed["yellow"][1]))
    t4.forward(randint(assign_speed["purple"][0], assign_speed["purple"][1]))
    sleep(0.3)

turtle.write(f"{winner} is the winner!!")

if winner == bet:
    if real_odds[bet] > 0:
        winnings = bet_amount * (real_odds[bet] / 100)
    else:
        winnings = bet_amount * (100 / abs(real_odds[bet]))

    print(f"Congrats! Your Turt won! your winnings are ${winnings}")
    print(f"Your total payout: ${winnings + bet_amount}")
else:
    print("Your Turt lost :(")
    print(f"You lost ${bet_amount}, keep Gambling! Don't be a quitter!")

turtle.done()