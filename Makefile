FILE = mono

all:
	pdflatex $(FILE)
	bibtex $(FILE)
	pdflatex $(FILE)
	pdflatex $(FILE)

clean:
	rm $(FILE).pdf $(FILE).aux  $(FILE).bbl -f
