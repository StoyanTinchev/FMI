#include <C-Turtle/CTurtle.hpp>

namespace ct = cturtle;

int main(int argc, char** argv) {
	ct::TurtleScreen scr;
	ct::Turtle t(scr);

	t.write("red");
	t.left(90);
	t.forward(40);
	t.right(90);
	t.circle(45, 40, t.pencolor());
	t.forward(80);
	t.circle(90, 20, t.pencolor());
	t.right(180);
	t.circle(90, 20, t.pencolor());
	t.right(180);
	t.forward(80);
	t.circle(90, 20, t.pencolor());
	t.forward(80);
	t.right(180);
	t.circle(90, 20, t.pencolor());
	t.forward(80);
	t.right(180);
	t.right(180);
	t.penup();
	t.forward(40);
	return 0;
}