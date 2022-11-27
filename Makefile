install:
	@printf "\n[INFO] Cleaning previous installation (if any).\n\n"
	make clean
	mkdir ./include/temp
	@printf "\n[INFO] Dependency: pyinstaller."
	@printf "\n[HELP] Visit https://pypi.org/project/pyinstaller/ for info & installation.\n\n"
	pyinstaller src/readcfg.py -y
	make newcfg
	gcc -Wall ./src/modify.c -o ./dist/xmodify -lm
	gcc -Wall ./src/run.c -o ./dist/xrun -lm
	gcc -Wall ./src/esc.c -o ./xesc -lm
	@printf "\n[INFO] Installation completed.\n\n"

newcfg:
	@printf "\n[INFO] Generating configurations.\n\n"
	./dist/readcfg/readcfg cpe
	./dist/readcfg/readcfg rie
	@printf "\n[INFO] Generation of configurations completed.\n\n"

clean:
	rm -rf ./dist
	rm -rf ./build
	rm -rf ./src/__pycache__
	rm -rf ./readcfg.spec
	rm -rf ./include/temp
	rm -rf ./xesc