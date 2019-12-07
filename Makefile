FILE = mono

all:
	xelatex $(FILE)
	bibtex $(FILE)
	xelatex $(FILE)

clean:
	rm $(FILE).pdf $(FILE).aux  $(FILE).bbl -f
