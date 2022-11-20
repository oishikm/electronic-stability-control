install:
	pyinstaller src/readcfg.py -y

newcfg:
	./dist/readcfg/readcfg cpe
	./dist/readcfg/readcfg rie

clean:
	rm -rf ./dist
	rm -rf ./build
	rm -rf ./src/__pycache__
	rm -rf ./readcfg.spec