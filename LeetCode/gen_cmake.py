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


def create_question_dir(parent_dir, questions):
    for question in questions:
        question_dir = f"{parent_dir}/Q{question}"
        os.makedirs(question_dir, exist_ok=True)
        with open(f"{question_dir}/Solution.cpp", "w", encoding="UTF-8") as f:
            f.write("class Solution {\n")
            f.write("public:\n\n")
            f.write("};")


if __name__ == '__main__':
    list_all_files("Q0199")
    # create_question_dir("Q0199", [
    #     '0140',
    #     '0144',
    #     '0145',
    #     '0149',
    #     '0151',
    #     '0152',
    #     '0154',
    #     '0164',
    #     '0165',
    #     '0166',
    #     '0168',
    #     '0169',
    #     '0171',
    #     '0172',
    #     '0173',
    #     '0174',
    #     '0179',
    #     '0187',
    #     '0188',
    #     '0190',
    #     '0191',
    #     '0198',
    #     '0199'
    # ])
