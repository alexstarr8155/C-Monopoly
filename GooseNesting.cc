#include "GooseNesting.h"
#include "Player.h"

GooseNesting::GooseNesting() : Cell{"GOOSE NESTING"} {}

// updates the on_cell member that there is a player on such cell
void GooseNesting::action(std::shared_ptr<Player> p, bool b) {
	on_cell.at(p->getPlayerChar()) = true;
}
