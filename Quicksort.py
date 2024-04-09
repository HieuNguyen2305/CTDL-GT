def chiaMang(a, dau, cuoi):
    Mau = {'đỏ': 0, 'trắng': 1, 'xanh': 2}
    pivot = a[cuoi]
    i = dau - 1
    for j in range(dau, cuoi):
        if Mau[a[j]] < Mau[pivot]:
            i += 1
            a[i], a[j] = a[j], a[i]
    a[i + 1], a[cuoi] = a[cuoi], a[i + 1]
    return i + 1

def quicksort(a, dau, cuoi):
    if dau < cuoi:
        cm = chiaMang(a, dau, cuoi)
        quicksort(a, dau, cm - 1)
        quicksort(a, cm + 1, cuoi)

# Danh sách đầu vào
dayMau = ['xanh', 'đỏ', 'xanh', 'đỏ', 'đỏ', 'trắng', 'đỏ', 'xanh', 'trắng']

# Sắp xếp danh sách theo quy tắc quốc kỳ Hà Lan
quicksort(dayMau, 0, len(dayMau) - 1)

# In danh sách kết quả
print(dayMau)

def tronMang(a,b):
    Mau = {'đỏ': 0, 'trắng': 1, 'xanh': 2}
    mangDone=[]
    i=0
    j=0
    while i< len(a) and j < len(b):
        if Mau[a[i]] < Mau[b[j]]:
            mangDone.append(a[i])
            i+=1
        elif Mau[a[i]] > Mau[b[j]]:
            mangDone.append(b[j])
            j+=1
        else:
            mangDone.append(a[i])
            i+=1
            mangDone.append(b[j])
            j+=1
    while i < len(a):
        mangDone.append(a[i])
        i += 1

    while j < len(b):
        mangDone.append(b[j])
        j += 1

    return mangDone
# Danh sách mới chứa các phần tử (Xanh, Đỏ, Trắng)
dayMauMoi = ['đỏ', 'trắng', 'xanh']

# Trộn danh sách mới vào danh sách cũ
dayMauSauTron = tronMang(dayMau, dayMauMoi)

# In danh sách kết quả
print(dayMauSauTron)
