install:
	@printf "\n[INFO] Cleaning previous installation (if any)\n\n"
	make clean
	mkdir ./include/temp
	@printf "\n[INFO] Dependency: pyinstaller."
	@printf "\n[HELP] Visit https://pypi.org/project/pyinstaller/ for info & installation.\n\n"
	pyinstaller src/readcfg.py -y
	make newcfg

newcfg:
	./dist/readcfg/readcfg cpe
	./dist/readcfg/readcfg rie

clean:
	rm -rf ./dist
	rm -rf ./build
	rm -rf ./src/__pycache__
	rm -rf ./readcfg.spec
	rm -rf ./include/temp