# Struct 
- [Struct](#struct) trong C# là **value type**
- **operator overloading** phải để **static** -> không thể sử dụng **this**, phải có 2 tham số và bắt buộc phải có ít nhất 1 tham số là [Struct](#struct) đó

```csharp
internal struct Mystruct
{
    public int tu;
    public int mau;

    public Mystruct()
    {
        tu = 18;
        mau = 7;
    }
    
    public static double operator + (Mystruct obj, Mystruct other)
    {
        return (double)(obj.tu * other.mau + obj.mau * other.tu) / (obj.mau * other.mau);
    }
}
```
