import os


def list_all_files(directory):
    with open(f"{directory}/{directory}.cmake", "w") as f:
        for root, dirs, files in os.walk(directory):
            for file in files:
                file_full_path = os.path.join(root, file)
                if ".cmake" in file_full_path:
                    continue
                parts = file_full_path.split("\\")
                parts[0] = "list(APPEND SOURCES ${CMAKE_CURRENT_LIST_DIR}"
                line = "/".join(parts) + ")"
                f.write(line)
                f.write("\n")


list_all_files("Q0199")
