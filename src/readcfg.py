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

def generate_header(header_filename, filtered_cfg):
    datatype = {
        'mass' : 'float',
        'start_coord' : 'point_3d',
        'finish_coord' : 'point_3d',
        'target_time' : 'float',
        'indifferent_inertia' : 'float',
        'strength' : 'float'
    }
    cfg_dict = dict(filtered_cfg)
    with open(header_filename, "w") as cfg_header:
        cfg_header.write('#include\"libcpe.h\"\n')
        for key in cfg_dict.keys():
            cfg_header.write(f'{datatype[key]} {key} = {cfg_dict[key]};\n')

def main():
    cfg_filename = f'./cfg/{sys.argv[1]}.cfg'
    header_filename = f'./include/temp/{sys.argv[1]}.h'
    filtered_cfg = read_cfg(cfg_filename)
    generate_header(header_filename, filtered_cfg)

if __name__ == '__main__':
    main()    