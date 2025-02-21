import turtle
from  random import randint, sample, shuffle
from time import sleep


#ask how many turts they woud like to race
while True:
  try:
      turt_num = input("How many Turts would you like to race? ")
      if not turt_num.isdigit():
          raise ValueError("must be an integer")
      elif int(turt_num) >= 9:
          raise ValueError("you may not race more than 8 Turts")
      elif int(turt_num) <= 1:
          raise ValueError("you must race at least 2 Turts")
      else:
          turt_num = int(turt_num)
          break
  except ValueError as e:
      print(f"Invalid Input: {e}")


odds = []
#get random odds
for i in range(turt_num):
  odds.append(randint(200, 600))


colors = ["red", "blue", "green", "purple", "black", "orange", "yellow", "pink", "gold", "gray", "brown", "cyan"]
assign_odds = sample(odds, turt_num)


real_odds = {}
for i in range(turt_num):
  color = sample(colors, 1)[0]
  real_odds[color] = assign_odds[i]
  colors.remove(color)


tot_win_per = 0
per = 0


#get the win percentage of current odds (not equal to 100%)
real_per = {}
for color in real_odds:
  if real_odds[color] > 0:
      per = 100 / (real_odds[color] + 100)
      tot_win_per += per
      real_per[color] = per
  else:
      per = abs(real_odds[color]) / (abs(real_odds[color]) + 100)
      tot_win_per += per
      real_per[color] = per


#convert the odds to reflect a win total win percentage of 100%
for color in real_per:
  real_per[color] = (real_per[color] / tot_win_per) * 100
  #print(f"{color}: {round(real_per[color], 2)}%")
for color in real_odds:
  real_odds[color] = int(round((100 - real_per[color]) / real_per[color] * 100))


#assign speed based on win percent
assign_speed = {}
for color in real_odds:
  assign_speed[color] = (10 - (round(real_odds[color] / 200)), 15 + (round(real_odds[color] / 400)))
  #print(f"{color}: {assign_speed[color]}")

print("Gamble before we race our Turts!")
print("Odds:")
for color in real_odds:
  print(f"{color} is +{real_odds[color]}")


#get bet from user
while True:
  bet = input("Who would you like to bet on? ")
  if bet.lower() in real_odds:
      break
  else:
      print("bet on one of the colors")


while True:
  try:
      bet_amount = int(input("how much money would you like to bet? "))
      break
  except ValueError:
      print("Your bet must be a number")


print(f"${bet_amount} is on the line!!!")


#window setup
window = turtle.Screen()
window.title('Turtle Race!')
window.bgcolor('lightgreen')


finline = 250
draw_finline = finline
line_height = 400
top_lines = 150
cur_line_height = top_lines
bottom_lines = top_lines - line_height
line_height_alt = bottom_lines + ((line_height / turt_num) / 2)
startline = -250
turtle.penup()
turtle.hideturtle()
turtle.speed(0)
turtle.goto(startline, top_lines)
turtle.pendown()
turtle.color("gray")
turtle.goto(startline, bottom_lines)
turtle.penup()
turtle.goto(finline, top_lines)
turtle.pendown()
is_black = True
for i in range(2):
  for k in range(4):
      for j in range(4):
          turtle.color("white" if is_black else "black")
          cur_line_height -= line_height / 8
          turtle.goto(draw_finline, cur_line_height)
          turtle.color("black" if is_black else "white")
          cur_line_height -= line_height / 8
          turtle.goto(draw_finline, cur_line_height)
      draw_finline += 1
      turtle.goto(draw_finline, cur_line_height)
      for j in range(4):
          turtle.color("black" if is_black else "white")
          cur_line_height += line_height / 8
          turtle.goto(draw_finline, cur_line_height)
          turtle.color("white" if is_black else "black")
          cur_line_height += line_height / 8
          turtle.goto(draw_finline, cur_line_height)
      draw_finline += 1
      turtle.goto(draw_finline, cur_line_height)
  is_black = False


turts = {}
for color in real_odds:
  turts[color] = turtle.Turtle()
  turts[color].color(color)
  turts[color].shape('turtle')
  turts[color].penup()
  turts[color].goto(startline - 75, line_height_alt)
  turts[color].write(f"{color} +{real_odds[color]}", align="center", font=("Comic Sans MS", 10, "bold"))
  turts[color].goto(startline - 19, line_height_alt)
  turts[color].pendown()
  line_height_alt += line_height / turt_num

standings_top = 390
standings_height = 215
standings_bottom = standings_top - standings_height
standings_left = -400
standings_right = -225
standings_mid = standings_left - ((standings_left - standings_right) / 2)
standings_height_alt = (standings_top - 23) - (((standings_height - 23) / turt_num) / 2)
writer2 = turtle.Turtle()
writer2.hideturtle()
writer2.penup()
writer2.goto(standings_left, standings_top)
writer2.pendown()
writer2.goto(standings_right, standings_top)
writer2.goto(standings_right, standings_bottom)
writer2.goto(standings_left, standings_bottom)
writer2.goto(standings_left, standings_top)
writer2.penup()
writer2.goto(standings_mid, standings_top - 20)
writer2.write("Standings:", align="center", font=("Comic Sans MS", 12, "bold"))


for i in range(turt_num):
  writer2.goto(standings_left + 10, standings_height_alt)
  writer2.write(f"{i + 1}.", align="center", font=("Comic Sans MS", 8, "bold"))
  standings_height_alt -= (standings_height - 23) / turt_num
standings_height_alt = (standings_top - 23) - (((standings_height - 23) / turt_num) / 2)
writer = turtle.Turtle()
writer.hideturtle()
writer.penup()
writer.goto(0, 280)
writer.write("Turtles! On your marks!", align="center", font=("Comic Sans MS", 24, "bold"))
sleep(3)
writer.clear()
writer.write("3", align="center", font=("Comic Sans MS", 24, "bold"))
sleep(1)
writer.clear()
writer.write("2", align="center", font=("Comic Sans MS", 24, "bold"))
sleep(1)
writer.clear()
writer.write("1", align="center", font=("Comic Sans MS", 24, "bold"))
sleep(1)
writer.clear()
writer.write("GO!", align="center", font=("Comic Sans MS", 24, "bold"))




#run the race while nobody has crossed the finish line
winner = "none"
k=0
j=0
winner_list = []
winners_xcor = []
turts_xcor = {}
turts_prev_xcor = {}
turts_for = {}
turts_standings = []
turts_order = list(turts.keys())
writer3 = turtle.Turtle()
writer3.hideturtle()
writer3.penup()
while winner == "none":
   if k == 10:
       writer.clear()
       writer.write("Who Will Win?", align="center", font=("Comic Sans MS", 24, "bold"))
   shuffle(turts_order)
   for i in range(len(turts_order)):
      turts_prev_xcor[turts_order[i]] = turts[turts_order[i]].xcor()
      turts_for[turts_order[i]] = randint(int(assign_speed[turts_order[i]][0]), int(assign_speed[turts_order[i]][1]))
      turts[turts_order[i]].forward(turts_for[turts_order[i]])
      turts_xcor[turts_order[i]] = turts[turts_order[i]].xcor()
   turts_standings = sorted(turts_xcor.items(), key=lambda item: item[1], reverse=True)
   writer3.clear()
   for color, xcor in turts_standings:
      writer3.goto(standings_left + 20, standings_height_alt)
      writer3.color(color)
      writer3.write(f"{color}", font=("Comic Sans MS", 10, "bold"))
      standings_height_alt -= (standings_height - 23) / turt_num
   standings_height_alt = (standings_top - 23) - (((standings_height - 23) / turt_num) / 2)
   k+=1

   for i in range(len(turts_order)):
      if turts[turts_order[i]].xcor() >= finline - 18:
          j+=1
          winner_list.append(turts_order[i])
   if j == 1:
      winner = winner_list[0]
   if j > 1:
      writer.clear()
      writer.write("there has been a tie!", align="center", font=("Comic Sans MS", 24, "bold"))
      sleep(1)
      writer.clear()
      writer.write("Too booth review...", align="center", font=("Comic Sans MS", 24, "bold"))
      sleep(1)
      writer.clear()
      for i in range(len(turts_order)):
          turts[turts_order[i]].backward(int(turts_for[turts_order[i]]))
      sleep(1)
      for i in range(len(turts_order)):
          turts[turts_order[i]].forward(int(turts_for[turts_order[i]]))
      writer.write("Slow-Mo Replay!", align="center", font=("Comic Sans MS", 24, "bold"))
      sleep(1)
      writer.clear()
      for i in range(len(turts_order)):
           turts[turts_order[i]].backward(int(turts_for[turts_order[i]]))
      sleep(3)
      for i in range(len(turts_order)):
         turts[turts_order[i]].forward(int(turts_for[turts_order[i]]))
         sleep(1.5)
         if int(turts[turts_order[i]].xcor()) >= finline - 18:
           winner = turts_order[i]
           break




writer.clear()
writer.color(winner)
writer.write(f"{winner} is the winner!!", align="center", font=("Comic Sans MS", 24, "bold"))


if winner == bet:
  if real_odds[bet] > 0:
      winnings = round(bet_amount * (real_odds[bet] / 100), 2)
  else:
      winnings = round(bet_amount * (100 / abs(real_odds[bet])), 2)


  print(f"Congrats! Your Turt won! your winnings are ${winnings}")
  print(f"Your total payout: ${winnings + bet_amount}")
else:
  print("Your Turt lost :(")
  print(f"You lost ${bet_amount}, keep Gambling! Don't be a quitter!")
sleep(5)
turtle.done()
