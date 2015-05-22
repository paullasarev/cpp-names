What kind of problems trying to solve this tool?

In some large projects it is not so simple to find definition and declaration place of used C++ names.<br>'Large' means here projects that cannot be build by one 'solution' in MS terminology.<br>
<br>
So it would be nice to have a tool to automate the task of searching the required information.<br>
<br>
<h2>Main target</h2>
<ul><li>Extract namespace/class/method information from whole project source tree.<br>
</li><li>Place this information into <a href='http://en.wikipedia.org/wiki/Comma-separated_values'>csv</a> database file.<br>
</li><li>When information about C++ names will be presented in a structured form, we will be able to load it into Excel (or, for examle, in SQLite database) for further analysis.</li></ul>

<h2>Additional targets</h2>
<ul><li>Consistent application of the <a href='http://en.wikipedia.org/wiki/Test-driven_development'>test-driven development principles</a> in a C++ environment.<br>
</li><li>Using the <a href='http://en.wikipedia.org/wiki/Mock_object'>mock objects technology</a> for top-down design and feature-based development of the application in a C++ environment.<br>
</li><li>Create base parser for pluggable C++ source code processing</li></ul>

<h2>Links</h2>
<ul><li>DesignAndTechnologies<br>
</li><li>ProjectDashboard