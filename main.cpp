#include <ncurses.h>
#include <math.h>
#include <ctime>

int main() {
	int start_time = time(0);
	initscr();
	start_color();

	WINDOW *win = newwin(5, 7, 0, 0);
	init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	int run_time = 0;
	int s = 0;
	int m = 0;
	int h = 0;
	cbreak();
	nodelay(stdscr, TRUE);
	nodelay(win, TRUE);
	while(true) {
		napms(500);

		char input = getch();
		if (input == 'q') {
			delwin(win);
			endwin();
			return 0;
		}
		else {
			run_time = time(0) - start_time;
			h = run_time / 3600;
			m = (run_time % 3600) / 60;
			s = run_time % 60;
			wattron(win, COLOR_PAIR(1));
			mvwprintw(win, 1, 1, "s: %02d", s);
			mvwprintw(win, 2, 1, "m: %02d", m);
			mvwprintw(win, 3, 1, "h: %02d", h);
			wattroff(win, COLOR_PAIR(1));

			wattron(win, COLOR_PAIR(2));
			box(win, 0, 0);
			wattroff(win, COLOR_PAIR(2));

			wrefresh(win);
			refresh();

		}
	}

	endwin();
	return 0;
}
