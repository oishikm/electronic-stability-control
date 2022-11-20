# Read CFG files
import sys

def main():
    cfg_filename = f'./cfg/{sys.argv[1]}.cfg'
    with open(cfg_filename, "r") as cfg_file:
        cfg_file_data = cfg_file.read().strip().split('\n')
    filtered_cfg = []
    for line in cfg_file_data:
        line = line.split('#')[0]
        if len(line)>0:
            filtered_cfg.append(line.split('='))
            # print(line.split('='))

if __name__ == '__main__':
    main()    