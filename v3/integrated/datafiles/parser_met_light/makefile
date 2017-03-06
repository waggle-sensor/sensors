all: deep

deep: 
	./fetch_files.sh 
	./clean_files.sh
	./parse_plot.sh all

clean: 
	./clean_space.sh

pdf: 
	./parse_plot.sh all

6h: 
	./parse_plot.sh 6

8h: 
	./parse_plot.sh 8

12h: 
	./parse_plot.sh 12

24h: 
	./parse_plot.sh 24
