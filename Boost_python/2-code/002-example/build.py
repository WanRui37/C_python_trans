import os

current_dir = os.getcwd()

numeric_folders = []
for item in os.listdir(current_dir):
    if os.path.isdir(os.path.join(current_dir, item)) and item[0].isdigit():
        numeric_folders.append(item)

# 按数字部分对文件夹名进行排序
def get_numeric_prefix(folder_name):
    digits = ""
    for char in folder_name:
        if char.isdigit():
            digits += char
        else:
            break
    return int(digits)

numeric_folders.sort(key=get_numeric_prefix)


for ii, folder in enumerate(numeric_folders) :
    print(f"------正在执行第{ii}个命令---------")
    folder_path = os.path.join(current_dir, folder)
    os.chdir(folder_path)

    try:
        cpp_count = 0
        py_count = 0

        for file in os.listdir(folder_path):
            if file.endswith('.cpp'):
                cpp_count += 1
            elif file.endswith('.py'):
                py_count += 1

        if cpp_count + py_count > 2:
            raise ValueError("文件数量超过 2 个")

        for file in os.listdir(folder_path):
            if file.endswith('.cpp'):
                cpp_file = os.path.join(folder_path, file)
                so_file = os.path.splitext(cpp_file)[0] + '.so'
                relative_cpp_file = os.path.basename(cpp_file)
                relative_so_file = os.path.basename(so_file)
                compile_command = f"g++ -shared -o {relative_so_file} -fPIC {relative_cpp_file} -I /usr/include/python3.8 -lboost_python38"
                print(f"正在执行命令: {compile_command}")
                os.system(compile_command)

        for file in os.listdir(folder_path):
            if file.endswith('.py'):
                py_command = f"python {file}"
                print(f"正在执行 Python 文件: {py_command}")
                os.system(py_command)

    except:
        compile_command = f"bash ./build.sh"
        print(f"正在执行命令: {compile_command}")
        os.system(compile_command)
    
    os.chdir(current_dir)