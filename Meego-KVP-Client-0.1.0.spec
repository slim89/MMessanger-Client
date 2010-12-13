
Name:Meego-KVP-Client
Version:0.1.0
Release:1
Summary:  <insert up to 60 chars description>
Source:%{name}-%{version}.tar.gz
License:lgpl
Prefix:/

%description
 <insert long description, indented with spaces>
%prep
%setup -q -n %{name}-%{version}

%build
qmake -r -spec linux-g++ CONFIG+=debug && make -w

%install
rm -rf %{buildroot}
mkdir -p %{buildroot}
make install INSTALL_ROOT=%{buildroot}

mkdir -p %{buildroot}/usr/share
mkdir -p %{buildroot}/usr/share/Meego-KVP-Client
mkdir -p %{buildroot}/usr/share/Meego-KVP-Client/style
install style/Meego-KVP-Client.css %{buildroot}/usr/share/Meego-KVP-Client/style
install style/background.svg %{buildroot}/usr/share/Meego-KVP-Client/style
install style/button.svg %{buildroot}/usr/share/Meego-KVP-Client/style
install style/logo.gif %{buildroot}/usr/share/Meego-KVP-Client/style

%files
/

%clean
make clean
rm -rf %{buildroot}

%files
/

