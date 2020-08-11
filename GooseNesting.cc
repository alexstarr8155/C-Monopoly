#include "GooseNesting.h"
#include "Player.h"

GooseNesting::GooseNesting() : Cell{"GOOSE NESTING"} {}

void GooseNesting::action (std::shared_ptr<Player> p, bool b) {
	on_cell.at(p->getPlayerChar()) = true;
}
