import os

current_dir = os.getcwd()

numeric_folders = []
for item in os.listdir(current_dir):
    if os.path.isdir(os.path.join(current_dir, item)) and item[0].isdigit():
        numeric_folders.append(item)

def get_numeric_prefix(folder_name):
    digits = ""
    for char in folder_name:
        if char.isdigit():
            digits += char
        else:
            break
    return int(digits)

numeric_folders.sort(key=get_numeric_prefix)

for ii, folder in enumerate(numeric_folders):
    print(f"------正在处理第 {ii} 个文件夹 {folder} 中的 .so 文件、无后缀文件和__开头的文件夹---------")
    folder_path = os.path.join(current_dir, folder)
    delete_so_command = f"rm -f {os.path.join(folder_path, '*.so')}"
    print(f"正在执行命令: {delete_so_command}")
    os.system(delete_so_command)

    for file in os.listdir(folder_path):
        file_path = os.path.join(folder_path, file)
        if os.path.isfile(file_path) and '.' not in file:
            delete_command = f"rm -f {file_path}"
            print(f"正在执行命令: {delete_command}")
            os.system(delete_command)
        elif os.path.isdir(file_path) and file.startswith('__'):
            delete_dir_command = f"rm -rf {file_path}"
            print(f"正在执行命令: {delete_dir_command}")
            os.system(delete_dir_command)