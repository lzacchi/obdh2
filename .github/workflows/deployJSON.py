#!/usr/bin/python3

import sys
import os
import json
import re


if len(sys.argv) <= 2:
	print("\n")
	print("Wrong arguments")
	print("Use: ./test-deployer [flag] [parameter]")
	print("\n")
	sys.exit(1)
else:
    if sys.argv[1] == '--generate':
        # Directory path and list
        path = "./" + sys.argv[2]
        file_dir = os.listdir(path)

        print(len(path), " test files detected in " + sys.argv[2] +  " folder")

    files = {
        "include": []
    }

    for file in path:
        file_name = file
        file_path = path + file

        file_info = {
            "name": file_name,
            "path": file_path
        }

        files['include'].append(file_info)

    # conver to json
    json_target = json.dumps(files)

    with open(".github/workflows/test_list.json", "w") as json_file:
        json_file.write(json_target)
    json_file.close()

    print("JSON created successfully for " + sys.argv[2] + " folder")
