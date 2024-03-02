CXX = g++
CXXFLAGS = -O2 -g
TARGET = random_pdf.x
DATA_FILE = data.txt
PDF_FILE = random_pdf.pdf
SEED_VALUES = 1 2 5
NSAMPLES = 1000
MU = 3.5
SIGMA = 0.4
XMIN = 2.7
XMAX = 4.6
NBINS = 50

.PHONY: all clean

all: $(PDF_FILE)

$(TARGET): random_pdf.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

$(DATA_FILE): $(TARGET)
	for SEED in $(SEED_VALUES); do \
	    ./$(TARGET) $$SEED $(NSAMPLES) $(MU) $(SIGMA) $(XMIN) $(XMAX) $(NBINS) > datos$$SEED.txt; \
	done

$(PDF_FILE): $(DATA_FILE)
	echo "set term pdf" > script.gp
	echo "set output '$(PDF_FILE)'" >> script.gp
	echo "set grid" >> script.gp
	echo "set title 'Densidad de Probabilidad'" >> script.gp
	echo "set xlabel 'Valores'" >> script.gp
	echo "set ylabel 'ValoresPDF'" >> script.gp
	echo "plot \\" >> script.gp
	for SEED in $(SEED_VALUES); do \
		echo "'datos$$SEED.txt' using 1:2 with points notitle lt $$SEED pt 6 ps 0.4, '' using 1:2 with lines title 'SEED $$SEED' lt $$SEED lw 1, \\" >> script.gp; \
	done
	gnuplot script.gp



clean:
	rm -f $(TARGET) $(DATA_FILE) $(PDF_FILE) script.gp*
