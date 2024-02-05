#This code was created to play the game of pong. The program uses Turtle(an inbuilt graphic module in python). The game consists of tow paddles and a ball. Each paddle is controlled by the user and the ball in controlled VIA the computer. 
#A while loop alows the game to run until the either player gets scored on 3 times, once that happens the scoreboard will dissapear, the player that won will be displayed and the program will close.#

import turtle #the graphic module used to display the game

#create the screen
screen = turtle.Screen() #initalize a turtle graphic screen
screen.title("Pong: Created by Cody Hagel") #screen title name
screen.bgcolor("black") #declare bacground color
screen.setup(width=1000, height=600) #declare size of the screen

#creation of the left paddle
left_paddle = turtle.Turtle() #initalize a new object
left_paddle.speed(0) #sets animation speed
left_paddle.shape("square") #declares the shape of the paddle
left_paddle.color("cyan") #declares color of the paddle
left_paddle.shapesize(stretch_wid=6, stretch_len=2) #declare the aspects of the paddle
left_paddle.penup() #allows the object to move without drawing a line
left_paddle.goto(-400, 0) #delcare positioning of the paddle, x coorilates to left-right, y coorilates to up-down


#creation of the right paddle
right_paddle = turtle.Turtle()#initalize a new object
right_paddle.speed(0)
right_paddle.shape("square")
right_paddle.color("red") #used a different color to differentiate users
right_paddle.shapesize(stretch_wid=6, stretch_len=2)
right_paddle.penup()
right_paddle.goto(400, 0) #left space behind the paddles to better show ball hitting edges

#creation of the ball
play_ball = turtle.Turtle() #initalize a new object
play_ball.speed(10) #sets animation speed
play_ball.shape("circle")
play_ball.color("white")
play_ball.penup() 
play_ball.goto(0, 0) #sets ball in middle of the screen
play_ball.dx = 5 #sets the ball movement speed in the x direction
play_ball.dy = 5 #sets the balls movement speed in the y directioon

#set the inital score, both should start at 0
player_1 = 0 #initalize a variable named player_1, will represent the paddle on the left
player_2 = 0 #initalize a variable named player_2, will represent the paddle on the right

# set up the score display
score = turtle.Turtle() #initalize a new turtle object
score.speed(0) #set movement speed
score.color("white") #set color of scoreboard
score.penup() 
score.hideturtle()
score.goto(0, 260)
#write the text dictated in first quotation set, align dictates that the score will be centered
#font indicates the font in which text will be written, the size of said text, the text is of type normal
score.write("Player 1 : 0       Player 2 : 0",
            align = "center", font=("Times New Roman", 24, "normal"))

#Functions that will allow the paddles to move
def cyanUp(): #function to move cyan paddle up
    y = left_paddle.ycor() #gets current y-coordinate 
    y += 20 #increases y-coordinate by 20
    left_paddle.sety(y) #set new value of y-coordinate

def cyanDown(): #function to move cyan paddle down
    y = left_paddle.ycor()
    y -= 20 #decareses the y-coordinate by 20
    left_paddle.sety(y)

def redUp(): #fucntion to move red paddle down
    y = right_paddle.ycor()
    y += 20
    right_paddle.sety(y)

def redDown(): #function to move red paddle down
    y = right_paddle.ycor()
    y -= 20
    right_paddle.sety(y)

#Setting the keyboard binding for each function
screen.listen() #make sure that the screen is listening for inputtted events
screen.onkeypress(cyanUp, "w") #mapping the up-movement key for the left paddle to w
screen.onkeypress(cyanDown, "s") #mapping the down-movement key for the left paddle to s
screen.onkeypress(redUp, "Up") #mapping the up-movement key for the right paddle to up arrow key
screen.onkeypress(redDown, "Down") #mapping the down-movement key for the right paddle to down arrow key

#While statement to keep game running until stopped
while True:
    screen.update() #constantly update the screen

    play_ball.setx(play_ball.xcor()+play_ball.dx) #set the x-coordinate of the ball
    play_ball.sety(play_ball.ycor()+play_ball.dy) #set the y coordinate of the ball

    #Series of if-statements to check for border collision
    if play_ball.ycor() > 280:
        play_ball.sety(280)
        play_ball.dy *= -1

    if play_ball.ycor() < -280:
        play_ball.sety(-280)
        play_ball.dy *= -1

    if play_ball.xcor() > 600:
        play_ball.goto(0, 0)
        play_ball.dy *= -1
        player_1 += 1
        score.clear()
        score.write("Player 1 : {}       Player 2 : {}".format(
            player_1, player_2), align= "center", font=("Times New Roman", 24, "normal"))
        
    if play_ball.xcor() < -600:
        play_ball.goto(0, 0)
        play_ball.dy *= -1
        player_2 += 1
        score.clear()
        score.write("Player 1 : {}       Player 2 : {}".format(
            player_1, player_2), align= "center", font=("Times New Roman", 24, "normal"))
        
    #series of if sttaements for paddle collision   
    if (play_ball.xcor() > 360 and play_ball.xcor() < 370) and (play_ball.ycor() 
            < right_paddle.ycor()+40 and play_ball.ycor() > right_paddle.ycor()-40):
        play_ball.setx(360)
        play_ball.dx *= -1

    if (play_ball.xcor() < -360 and play_ball.xcor() > -370) and (play_ball.ycor()
            < left_paddle.ycor()+40 and play_ball.ycor() > left_paddle.ycor()-40):
        play_ball.setx(-360)
        play_ball.dx *= -1

    #win condition statements
    if player_1 == 3:
        score.clear()
        score.write("Player 1 Wins!!!", align = "center", font = ("Times New Roman", 24, "normal"))
        break

    if player_2 == 3:
        score.clear()
        score.write("Player 2 Wins!!!", align = "center", font = ("Times New Roman", 24, "normal"))
        break