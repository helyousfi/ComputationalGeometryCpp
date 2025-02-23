import os
import re

def find_header_files(root_dir):
    """ Recursively find all .h files in the project directory. """
    header_files = []
    for root, _, files in os.walk(root_dir):
        for file in files:
            if file.endswith(".h"):
                header_files.append(os.path.join(root, file))
    return header_files

def parse_header_file(file_path):
    """ Extract class names, attributes, and methods from a .h file. """
    with open(file_path, 'r', encoding='utf-8') as file:
        content = file.read()

    class_structure = {}

    # Match class definitions
    class_matches = re.findall(r'class\s+(\w+)\s*(:\s*public\s+\w+)?\s*{', content)
    for match in class_matches:
        class_name = match[0]
        class_structure[class_name] = {'attributes': [], 'methods': [], 'file': os.path.basename(file_path)}

        # Match attributes (private, protected, public sections)
        attributes = re.findall(r'(private|protected|public):\s*([^}]*)', content, re.DOTALL)
        for access, attr_block in attributes:
            attr_lines = attr_block.split("\n")
            for line in attr_lines:
                line = line.strip()
                if line and not line.startswith("//") and ";" in line:  # Avoid comments
                    class_structure[class_name]['attributes'].append(f"{access}: {line}")

        # Match methods (assuming they end with a semicolon)
        method_matches = re.findall(r'(\w[\w\s\*&]+)\s+(\w+)\(([^)]*)\)\s*;', content)
        for return_type, method_name, params in method_matches:
            method_signature = f"{return_type.strip()} {method_name}({params.strip()})"
            class_structure[class_name]['methods'].append(method_signature)

    return class_structure

def generate_project_structure(root_dir):
    """ Generates a structured representation of the project. """
    header_files = find_header_files(root_dir)
    project_structure = {}

    for file in header_files:
        class_data = parse_header_file(file)
        project_structure.update(class_data)

    return project_structure

def print_structure(structure):
    """ Pretty-print the project structure. """
    for class_name, details in structure.items():
        print(f"Class: {class_name} (File: {details['file']})")
        print("  Attributes:")
        for attr in details['attributes']:
            print(f"    - {attr}")
        print("  Methods:")
        for method in details['methods']:
            print(f"    - {method}")
        print("-" * 60)

if __name__ == "__main__":
    project_root = os.path.dirname(os.path.abspath(__file__))  # Folder where the script is placed
    structure = generate_project_structure(project_root)
    print_structure(structure)
