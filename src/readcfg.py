# Read CFG files
# Oishik Mukhopadhyay | 20 November 2022

import sys

def read_cfg(cfg_filename):
    with open(cfg_filename, "r") as cfg_file:
        cfg_file_data = cfg_file.read().strip().split('\n')
    filtered_cfg = []
    for line in cfg_file_data:
        line = line.split('#')[0]
        if len(line)>0:
            filtered_cfg.append(line.strip().split('='))
    return filtered_cfg

def generate_header(filename, filtered_cfg):
    
    pass

def main():
    cfg_filename = f'./cfg/{sys.argv[1]}.cfg'
    filtered_cfg = read_cfg(cfg_filename)
    for line in filtered_cfg:
        print(line)

if __name__ == '__main__':
    main()    