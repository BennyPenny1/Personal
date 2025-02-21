import turtle
from math import pi

while True:
    try:
        sides = input("how many sides do you want your polygon to have? ")
        if not sides.isdigit():
            raise ValueError("Input must be an integer")
        elif int(sides) <= 2:
            raise ValueError("Input must have more than 2 sides to make a shape dummy")
        elif int(sides) > 10000:
            raise ValueError("lets keep the sides to less than 10000 :)")
        else:
            sides = int(sides)
            break
    except ValueError as e:
        print(e)

polygons = {
    3: "Triangle",
    4: "Quadrilateral",
    5: "Pentagon",
    6: "Hexagon",
    7: "Heptagon",
    8: "Octagon",
    9: "Nonagon",
    10: "Decagon",
    11: "Hendecagon",
    12: "Dodecagon",
    13: "Tridecagon",
    14: "Tetradecagon",
    15: "Pentadecagon",
    16: "Hexadecagon",
    17: "Heptadecagon",
    18: "Octadecagon",
    19: "Enneadecagon",
    20: "Icosagon",
    30: "Triacontagon",
    40: "Tetracontagon",
    50: "Pentacontagon",
    60: "Hexacontagon",
    70: "Heptacontagon",
    80: "Octacontagon",
    90: "Enneacontagon",
    100: "Hectogon",
    1000: "Chiliagon",
    10000: "Myriagon",
}
for sides_num in polygons:
    if sides > sides_num:
        continue
    else:
        name = polygons[sides] 
while True:
    try:
        length = input(f"how what is the length of the sides in you're {name}? ")
        if not length.isdigit():
            raise ValueError("Must be an integer")
        elif int(length) <= 0:
            raise ValueError("length must be more than 1")
        else:
            length = int(length)
            break
    except ValueError as e:
        print(f"Invalid Input: {e}")

radius = (length * sides) / (2 * pi)


window = turtle.Screen()
window.title('Polygons!')
window.bgcolor("#d3d3d3")

turt = turtle.Turtle()
turt.hideturtle()
turt.penup()
turt.goto(0,(radius - (radius * 2)))
turt.left(180)
turt.pendown()


for i in range(sides):
    turt.right(360/ sides)
    turt.forward(length)
print(f"you should be proud of your {name}.")

turtle.done()
