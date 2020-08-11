#include "Board.h"
#include "BoardDisplay.h"

int main() {

	Board game = Board(4);
	BoardDisplay boardDisplay;

	boardDisplay.display(game);
}
