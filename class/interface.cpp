class ErrorLogInterface
{
	public:
	    virtual bool OpenLog(const char *strFilename) = 0;
	    virtual bool CloseLog() = 0;
	    virtual bool WriteError(const char *strErrorMessage) = 0;
};

// Any class inheriting from IErrorLog must provide implementations 
// for all three functions in order to be instantiated. 
class FileErrorLog: public ErrorLogInterface {
    virtual bool OpenLog(const char *strFilename) {}
    virtual bool CloseLog() {}
    virtual bool WriteError(const char *strErrorMessage) {}
    void print() {}
};

double MySqrt(double dValue, ErrorLogInterface& cLog)
{
    if (dValue < 0.0)
    {
        cLog.WriteError("Tried to take square root of value less than 0");
        return 0.0;
    }
    else
        return dValue;
}

int main() {
	FileErrorLog f;
	double dValue = 5;
	MySqrt(dValue, f);
}

